#include "roboticarm.h"
#include "ui_roboticarm.h"
#include <QMouseEvent>
#include <QIODevice>
#include <QTouchEvent>
#include <QObject>
#include <QGraphicsScene>
#include "senddata.h"
#include <QGraphicsSceneMouseEvent>
#include <QDesktopWidget>
#include <QRect>
#include <unistd.h>
#include <QPixmap>
#include <QTransform>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTextStream>


//static char* mInterface = "/dev/ttyUSB0";
static char* mInterface = "/dev/ttymxc3";

RoboticArm::RoboticArm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoboticArm)
{
    int i=0;
    ui->setupUi(this);
    ui->centralWidget->setMouseTracking(true);

    ui->lblError->setText("");

    for(i=0; i<6000; i=i+100){
        ui->cmbSpeed->addItem(QString::number(i));
    }
    ui->cmbSpeed->setCurrentIndex(20);

    /* Data port initialize */
    data = new SendData();
    int lFreshStart = data->Init(mInterface, B115200);

    /* Data port initialize */
    /* Graphic render */
    scene = new MyGraphicsView();
    scene->mode = POSITION_MODE;
    scene->setScene(ui->graphicsView->width()-5,ui->graphicsView->height()-5);
    scene->gwH = ui->graphicsView->height()-5;
    scene->gwW = ui->graphicsView->width()-5;
    scene->sldXM = ui->sldX->maximum();
    scene->sldYM = ui->sldZ->maximum();
    ui->graphicsView->setScene(scene);

    /* Insert image of arm */
    QGraphicsScene *scene1 = new QGraphicsScene();
    this->defaultPath = qApp->applicationDirPath();
    this->path = this->defaultPath + "/arm.png";
    QPixmap ImagePixmap;
    ImagePixmap.load(path);
    scene1->addPixmap(ImagePixmap);
    scene1->setSceneRect(0,0,ui->gwArm->width()-5,ui->gwArm->height()-5);
    ui->gwArm->setScene(scene1);

    /* Game 2 - ludo */
    ui->lblMoving->setText("Click on Shuffle!");
    game2 = new Game2();
    game2->init(data, GAME2_SPEED, GAME2_TOUCH, GAME2_ANGLE, this->defaultPath);
    MyGraphicsView* c2 = game2->getCube();
    ui->gwCube2->setScene(c2);
    c2->gwH = ui->gwCube2->height();
    c2->gwW = ui->gwCube2->width();
    /* Game BTNS*/
    connect( ui->btnNext, SIGNAL(clicked()), game2, SLOT(Next()));
    connect( ui->btnHome, SIGNAL(clicked()), game2, SLOT(Home()));
    connect( ui->btnShuffle2, SIGNAL(clicked()), game2, SLOT(Shuffle()));
    connect(game2, SIGNAL(game_error(int)), this, SLOT(printError(int)));
    connect(game2, SIGNAL(game2_start()), this, SLOT(gameStart()));
    connect(game2, SIGNAL(game2_end()), this, SLOT(gameEnd()));
    connect(ui->btnAutoPlay, SIGNAL(clicked()), game2, SLOT(AutoPlay()));
    connect(ui->btnAutoPlay, SIGNAL(clicked()), this, SLOT(AutoPlay()));
    ui->btnNext->setVisible(false);

    pitch = new MyGraphicsView();
    pitch->mode = GAME2_MODE;
    ui->gwGame2->setScene(pitch);
    this->path = this->defaultPath + "/game.png";
    pitch->initPitch(this->path);
    pitch->showFigure(0);
    connect(pitch, SIGNAL(clicked_pitch(int)), game2, SLOT(setPosition(int)));

    drawingGame = new DrawGame();
    drawingGame->init(data, DRAWGAME_SPEED, DRAWGAME_TOUCH, DRAWGAME_ANGLE, this->defaultPath);

    connect(ui->drawWidget, SIGNAL(trackChanged()), this, SLOT(reloadTrack()));
    connect(ui->btnHome_2, SIGNAL(clicked()), drawingGame, SLOT(Home()));
    connect(ui->btnShuffle2_2, SIGNAL(clicked()), drawingGame, SLOT(Shuffle()));
    connect(ui->btnAutoPlay_2, SIGNAL(clicked()), drawingGame, SLOT(AutoPlay()));
    connect(ui->btnDrawGame, SIGNAL(clicked()), this, SLOT(drawGame()));
    connect(drawingGame, SIGNAL(drawGame_error(int)), this, SLOT(printError(int)));
    connect(drawingGame, SIGNAL(drawGame_start()), this, SLOT(gameStart()));
    connect(drawingGame, SIGNAL(drawGame_end()), this, SLOT(gameEnd()));
    connect(ui->btnAutoPlay_2, SIGNAL(clicked()), this, SLOT(AutoPlay()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(cancel()));

    /* DrawGame */
    ui->lblMoving_2->setText("Click on Shuffle!");
    MyGraphicsView* c3 = drawingGame->getCube();
    ui->gwCube2_2->setScene(c3);
    c3->gwH = ui->gwCube2_2->height();
    c3->gwW = ui->gwCube2_2->width();

    draw = new MyGraphicsView();
    ui->drawWidget->hide();
    ui->drawArea->setScene(draw);
    this->path = this->defaultPath + "/drawGame.png";
    draw->initPitch(this->path);
    drawingGame->num = 0;
    draw->showFigureDynamic(drawingGame->num);
    ui->btnCancel->setVisible(false);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));

    /* draw arm and border*/
    this->visualiseBorder();
    this->visualiseArm();
    for(i=0; i<sizeof(game2->CalibratingPositions)/sizeof( game2->CalibratingPositions[0] ); i++){
        ui->cmbGamePositions->addItem("Position "+QString::number(i));
    }
    connect( ui->btnSetAsPosition, SIGNAL(clicked()), this, SLOT(SetAsPosition()));


    /* video routine */
    Video* v = new Video();
    //v->init("/dev/video18");
    //v->init("/home/caufa/Downloads/build-RoboticArm-Desktop_Qt_5_12_0_GCC_64bit-Debug/video.mp4");
    connect( ui->btnPlay, SIGNAL(clicked()), v, SLOT(Play()));
    connect( ui->btnPause, SIGNAL(clicked()), v, SLOT(Pause()));

    this->initCam();

    /* others */
    ui->btnSet->setVisible(false);

    char* lResponse = data->GetInitResponse();
    QTextStream(stdout) << "Response:" << lResponse<<"; fresh "<< !strcmp(lResponse,"noInit") << endl;
    if(lFreshStart > 0){
        QTextStream(stdout) << "checking response" << endl;
        bool exists = strstr(lResponse, "noInit") != NULL;
        if(!exists){
            QTextStream(stdout) << "values" << endl;
            SortValues(lResponse);
        }
        else{
            QTextStream(stdout) << "no values" << endl;
            //data->setTime(3000);
            data->SetZero();
            //QTextStream(stdout) << "Calibrating, please wait." << endl;
            //calibrateArm();
            //QTextStream(stdout) << "Calibration done." << endl;
            ui->sldRotar->setValue(90);
        }
    }
    else{
        QTextStream(stdout) << "freshstart" << endl;
        data->setTime(1500);
        data->SetZero();
        /*QTextStream(stdout) << "Calibrating, please wait." << endl;
        calibrateArm();
        QTextStream(stdout) << "Calibration done." << endl;*/
        ui->sldRotar->setValue(90);
    }


    /* when change position, change sliders too */
    connect(scene,SIGNAL(newPos()),this,SLOT(setSld()));

    /* set rotation */
    connect(ui->sldRotar, SIGNAL(valueChanged(int)),data, SLOT(setServo0()));
    connect(ui->sldRotar, SIGNAL(valueChanged(int)),this, SLOT(rotarText(int)));
    connect(ui->sldRotar, SIGNAL(valueChanged(int)),data, SLOT(SendAngle(int)));

    /* set touch of hand */
    connect(ui->sldHand, SIGNAL(valueChanged(int)),data, SLOT(setServo4()));
    connect(ui->sldHand, SIGNAL(valueChanged(int)),this, SLOT(handText(int)));
    connect(ui->sldHand, SIGNAL(valueChanged(int)),data, SLOT(SendAngle(int)));


    /* set position by Slider */
    ui->sldX->setVisible(false);
    ui->sldZ->setVisible(false);
    connect(ui->sldX, SIGNAL(valueChanged(int)),data, SLOT(setZ(int)));
    connect(ui->sldX, SIGNAL(valueChanged(int)),this, SLOT(DrawMove()));

    connect(ui->sldZ, SIGNAL(valueChanged(int)),data, SLOT(setX(int)));
    connect(ui->sldZ, SIGNAL(valueChanged(int)),this, SLOT(DrawMove()));


    /* set degree of hand */
    connect(ui->sldHand_2, SIGNAL(valueChanged(int)),data, SLOT(setAngle(int)));
    connect(ui->sldHand_2, SIGNAL(valueChanged(int)),this, SLOT(setSld()));

    /* Print error */
    connect(data, SIGNAL(Error(int)), this, SLOT(printError(int)));

    /* set speed of servo motors */
    connect(ui->cmbSpeed, SIGNAL(activated(QString)), data, SLOT(setTime(QString)));


    /* manual control */
    connect(ui->sldS1, SIGNAL(valueChanged(int)),data, SLOT(setServo0()));
    connect(ui->sldS1, SIGNAL(valueChanged(int)),data, SLOT(SendAngle(int)));

    connect(ui->sldS2, SIGNAL(valueChanged(int)),data, SLOT(setServo1()));
    connect(ui->sldS2, SIGNAL(valueChanged(int)),data, SLOT(SendAngle(int)));

    connect(ui->sldS3, SIGNAL(valueChanged(int)),data, SLOT(setServo2()));
    connect(ui->sldS3, SIGNAL(valueChanged(int)),data, SLOT(SendAngle(int)));

    connect(ui->sldS4, SIGNAL(valueChanged(int)),data, SLOT(setServo3()));
    connect(ui->sldS4, SIGNAL(valueChanged(int)),data, SLOT(SendAngle(int)));

    connect(ui->sldS5, SIGNAL(valueChanged(int)),data, SLOT(setServo4()));
    connect(ui->sldS5, SIGNAL(valueChanged(int)),data, SLOT(SendAngle(int)));

    /* Exit application */
    connect( ui->btnClose, SIGNAL(clicked()), qApp, SLOT(quit()));

    if(data->moveXYZ() == 0){
        scene->clear();
        this->visualiseBorder();
        this->visualiseArm();
    }//*/
}

void RoboticArm::drawGame(){
    ui->drawWidget->show();
    setButtonsDrawGame(false);
    cam->setMoving(true);
}


void RoboticArm::reloadTrack(){
    draw->setPoints(ui->drawWidget->getPositionPoints());
    draw->savePoints(this->defaultPath);
    ui->drawWidget->hide();
    draw->clear();
    this->path = this->defaultPath + "/drawGame.png";
    drawingGame->loadPoints(this->defaultPath);
    drawingGame->num = 0;
    drawingGame->Home();
    draw->initPitch(this->path);
    draw->showFigureDynamic(drawingGame->num);
    setButtonsDrawGame(true);
    cam->setMoving(false);
}


void RoboticArm::cancel(){
    ui->drawWidget->hide();
    setButtonsDrawGame(true);
    cam->setMoving(false);
}

void RoboticArm::initCam(){
    /* Camera routine */
    cam = new Camera();
    cam->Play();
    connect(cam,SIGNAL(dice_find(int)),this,SLOT(diceShow(int)));
    ui->gwCameraGame->setScene(cam->getScene());
    ui->gwCameraGame_2->setScene(cam->getScene());
}


void RoboticArm::setButtonsDrawGame(bool value){
    ui->btnShuffle2_2->setVisible(value);
    ui->btnHome_2->setVisible(value);
    ui->btnAutoPlay_2->setVisible(value);
    ui->btnDrawGame->setVisible(value);
    ui->btnCancel->setVisible(!value);
}


void RoboticArm::calibrateArm(){
    data->SolveCoordinates(120,70,100,-90);
    usleep(1500*1000);
    data->SolveCoordinates(170,0,30,-90);
    usleep(1500*1000);
    data->SolveCoordinates(120,0,100,-90);
    usleep(1500*1000);
    data->setServo0();
    data->SendAngle(120);
    usleep(1500*1000);
    data->setTime(3000);
    data->SendAngle(20);
    usleep(3000*1000);
    data->setTime(1500);
    data->SendAngle(70);
    usleep(1500*1000);
    data->SolveCoordinates(50,0,100,-90);
    usleep(1500*1000);
}

void RoboticArm::SetAsPosition(){
    int c = ui->cmbGamePositions->currentIndex();

     game2->CalibratingPositions[c].setX(game2->firstPos.x()-data->X);
     game2->CalibratingPositions[c].setY(game2->firstPos.y()-data->Y);
     game2->CalibratingPositions[c].setZ(game2->firstPos.z()-data->Z);
    game2->save();

}

void RoboticArm::setSld(){
    ui->sldX->setValue(scene->X*10);
    ui->sldZ->setValue(scene->Y*10);
    //QTextStream(stdout) << "z" << ui->sldZ->value() << " x"<<ui->sldX->value()<< endl;
    ui->lblHand->setText(QString::number(data->angle));

    if(data->moveXYZ() == 0){

        scene->clear();
        this->visualiseBorder();
        this->visualiseArm();
    }

}

void RoboticArm::DrawMove(){

    if(data->moveXYZ() == 0){

        scene->clear();
        this->visualiseBorder();
        this->visualiseArm();
    }

}

/* Show border for robotic arm */
void RoboticArm::visualiseBorder(){
    QPoint p,p1;
    for(int n=-90; n<180; n++){
        p = data->SolveMax(n);
        //if(n>0){
            scene->addLineReal(p1.x(),p1.y(),p.x(),p.y(),'r');
        //}

        //scene->crossX(p.x(),p.y());
        p1.setX(p.x());
        p1.setY(p.y());
    }
}


/* Show robotic arm in position */
void RoboticArm::visualiseArm(){
    scene->DrawPict(this->defaultPath + "/base.png", 33, 28.5, 0,28.5,0);
    scene->DrawPict(this->defaultPath + "/2.png",data->wristX,data->wristY,data->elbowX,data->elbowY,2);
    scene->DrawPict(this->defaultPath + "/1.png",data->elbowX,data->elbowY,data->shoulderX,data->shoulderY,1);
    scene->DrawPict(this->defaultPath + "/3.png",data->tipX,data->tipY,data->wristX,data->wristY,3);

    scene->crossX(ui->sldX->value(),ui->sldZ->value());
    scene->addLineReal(data->baseX,data->baseY,data->shoulderX,data->shoulderY,'b');
    scene->addLineReal(data->shoulderX,data->shoulderY,data->elbowX,data->elbowY,'b');
    scene->addLineReal(data->elbowX,data->elbowY,data->wristX,data->wristY,'b');
    scene->addLineReal(data->wristX,data->wristY,data->tipX,data->tipY,'b');

}


/* Display errors and others texts */
void RoboticArm::printError(int e){
    if(ui->tabWidget->currentIndex() != 3){
        switch (e){
            case 0:
                ui->lblError->setText("");
                break;
            case 1:
                ui->lblError->setText("Impossible due to limited arm length!");
                break;
            case 2:
                ui->lblError->setText("Error 2.");
                break;
            case 3:
                ui->lblError->setText("Error 3.");
                break;
            case 4:
                ui->lblError->setText("Error 4.");
                break;
            case GAME2_ERROR_MAX_NUM:
                if(game2->autoPlay == 0){
                    ui->lblMoving->setText("Play again!");
                    ui->lblMoving->setVisible(true);
                    ui->btnShuffle2->setEnabled(true);
                    ui->btnAutoPlay->setEnabled(true);
                }
                else{
                    if(game2->num < 13){
                        game2->Shuffle();
                    }else{
                        game2->Home();
                    }
                }
                break;
            case GAME2_ERROR_END:
                break;
        }
    }
    else{
        switch (e){
            case DRAWGAME_ERROR_MAX_NUM:
                if(drawingGame->autoPlay == 0){
                    ui->lblMoving_2->setText("Play again!");
                    ui->lblMoving_2->setVisible(true);
                    ui->btnShuffle2_2->setEnabled(true);
                    ui->btnAutoPlay_2->setEnabled(true);
                    ui->btnDrawGame->setEnabled(true);
                }
                else{
                    if(drawingGame->num < (drawingGame->pointsCount - 1)){
                        drawingGame->Shuffle();
                    }else{
                        drawingGame->Home();
                    }
                }
                break;
        }
    }
}

/* recognized dice and play game */
void RoboticArm::diceShow(int num){
    if(ui->tabWidget->currentIndex() == 2){
        if(num != 0){
            game2->Dice(num);
        }else{
            game2->cube_set(num);
        }
        dice_b=num;
    }
    else if(ui->tabWidget->currentIndex() == 3){
        if(num != 0){
            drawingGame->Dice(num);
        }else{
            drawingGame->cube_set(num);
        }
        dice_drawGame=num;
    }
}

void RoboticArm::handText(int i){
    ui->lblHand_2->setText(QString::number(i));
}

void RoboticArm::rotarText(int i){
    ui->lblRotar->setText(QString::number(i));
    data->Y = i;
}

/* after game start */
void RoboticArm::gameStart(){
    if(ui->tabWidget->currentIndex() == 2){
        cam->setMoving(true);
        ui->btnShuffle2->setEnabled(false);
        ui->btnHome->setEnabled(false);
        if(game2->num == 0){
            ui->lblMoving->setText("Moving to Ready...");
            if(game2->autoPlay == 0){
                ui->btnAutoPlay->setEnabled(false);
            }
        }else if(game2->num == 13){
            ui->lblMoving->setText("Moving to Home...");
            if(game2->autoPlay == 0){
                ui->btnAutoPlay->setEnabled(false);
            }
        }else{
            ui->lblMoving->setText("Moving to "+QString::number(game2->num)+"...");
            if(game2->autoPlay == 0){
                ui->btnAutoPlay->setEnabled(false);
            }
        }
        ui->lblMoving->setVisible(true);
        ui->btnShuffle2->setText("Waiting...");
    }
    else if(ui->tabWidget->currentIndex() == 3){
        cam->setMoving(true);
        ui->btnShuffle2_2->setEnabled(false);
        ui->btnHome_2->setEnabled(false);
        ui->btnDrawGame->setEnabled(false);
        if(drawingGame->num == 0){
            ui->lblMoving_2->setText("Moving to Ready...");
            if(drawingGame->autoPlay == 0){
                ui->btnAutoPlay_2->setEnabled(false);
            }
        }else if(drawingGame->num == (drawingGame->pointsCount - 1)){
            ui->lblMoving_2->setText("Moving to Home...");
            if(drawingGame->autoPlay == 0){
                ui->btnAutoPlay_2->setEnabled(false);
            }
        }else{
            ui->lblMoving_2->setText("Moving to "+QString::number(drawingGame->num)+"...");
            if(drawingGame->autoPlay == 0){
                ui->btnAutoPlay_2->setEnabled(false);
            }
        }
        ui->lblMoving_2->setVisible(true);
        ui->btnShuffle2_2->setText("Waiting...");
    }
}

/* after one move of game end */
void RoboticArm::gameEnd(){
    if(ui->tabWidget->currentIndex() == 2){
        cam->setMoving(false);
        ui->btnShuffle2->setText("Shuffle");
        if(game2->num != 13){
            if(game2->autoPlay == 0){
                ui->lblMoving->setText("Click to Shuffle!");
                if(game2->autoPlay == 0){
                    ui->btnShuffle2->setEnabled(true);
                    ui->btnHome->setEnabled(true);
                    ui->btnAutoPlay->setEnabled(true);
                }
            }else{
                ui->lblMoving->setText("Auto Shuffle...");
            }
        }else{
            ui->lblMoving->setText("Winner!");
            if(game2->autoPlay == 0){
                ui->btnShuffle2->setEnabled(false);
                ui->btnAutoPlay->setEnabled(true);
                ui->btnHome->setEnabled(true);
            }
        }
        if(game2->num != 13)
            ui->btnShuffle2->setEnabled(true);
        pitch->showFigure(game2->num);

        if(game2->autoPlay == 1){
            if(game2->num < 13){
                timer->start(1000);
            }else{
                game2->Home();
            }
        }
    }
    else if(ui->tabWidget->currentIndex() == 3){
        cam->setMoving(false);
        ui->btnShuffle2_2->setText("Shuffle");
        if(drawingGame->num != (drawingGame->pointsCount - 1)){
            if(drawingGame->autoPlay == 0){
                ui->lblMoving_2->setText("Click to Shuffle!");
                if(drawingGame->autoPlay == 0){
                    ui->btnShuffle2_2->setEnabled(true);
                    ui->btnHome_2->setEnabled(true);
                    ui->btnAutoPlay_2->setEnabled(true);
                    ui->btnDrawGame->setEnabled(true);
                }
            }else{
                ui->lblMoving_2->setText("Auto Shuffle...");
            }
        }else{
            ui->lblMoving_2->setText("Winner!");
            if(drawingGame->autoPlay == 0){
                ui->btnShuffle2_2->setEnabled(false);
                ui->btnAutoPlay_2->setEnabled(true);
                ui->btnHome_2->setEnabled(true);
                ui->btnDrawGame->setEnabled(true);
            }
        }
        if(drawingGame->num != (drawingGame->pointsCount - 1))
            ui->btnShuffle2_2->setEnabled(true);
        draw->showFigureDynamic(drawingGame->num);

        if(drawingGame->autoPlay == 1){
            if(drawingGame->num < (drawingGame->pointsCount - 1)){
                timer->start(1000);
            }else{
                drawingGame->Home();
            }
        }
    }
}

/* Timer for automatic play */
void RoboticArm::timerTimeout(){
    if(ui->tabWidget->currentIndex() == 2){
        timer->stop();
        game2->Shuffle();
    }
    else if(ui->tabWidget->currentIndex() == 3){
        timer->stop();
        drawingGame->Shuffle();
    }
}


/* Show or hide buttons when automatic play */
void RoboticArm::AutoPlay(){
    if(ui->tabWidget->currentIndex() == 2){
        if(game2->autoPlay == 1){
            pitch->mode = OTHER_MODE;
            ui->btnShuffle2->setVisible(false);
            ui->btnHome->setVisible(false);
            ui->btnAutoPlay->setText("Stop auto");
        }else{
            pitch->mode = GAME2_MODE;
            ui->btnShuffle2->setVisible(true);
            ui->btnHome->setVisible(true);
            ui->btnAutoPlay->setText("Auto play");
            ui->btnAutoPlay->setEnabled(false);
        }

    }
    else if(ui->tabWidget->currentIndex() == 3){
        if(drawingGame->autoPlay == 1){
            pitch->mode = OTHER_MODE;
            ui->btnShuffle2_2->setVisible(false);
            ui->btnHome_2->setVisible(false);
            ui->btnDrawGame->setVisible(false);
            ui->btnAutoPlay_2->setText("Stop auto");
        }else{
            pitch->mode = GAME2_MODE;
            ui->btnShuffle2_2->setVisible(true);
            ui->btnHome_2->setVisible(true);
            ui->btnDrawGame->setVisible(true);
            ui->btnAutoPlay_2->setText("Auto play");
            ui->btnAutoPlay_2->setEnabled(false);
        }
    }
}

RoboticArm::~RoboticArm()
{
    delete ui;
    delete data;
    QTextStream(stdout) <<"Destruct UI and Data object" << endl;
}

inline int GetNumber (char* aSource, int *aResult){

    int scan_value = sscanf(aSource, "%d", aResult);

    if (scan_value == 0)
        return -1;
    else
        return 0;
}

inline bool isWhitespace(char* aArray){
    for(unsigned int i = 0; i<strlen(aArray);i++){
        if(!isspace(aArray[i]))
            return false;
    }
    return true;
}

void RoboticArm::SortValues(char *lBuffer){
    int s0,s1,s2,s3,s4,s5, lTime;
    s0=s1=s2=s3=s4=s5=lTime=0;
    char* lToken;
    int lServo;
    int lCounter = 0;

    lToken = strtok(lBuffer, " ");
    while( lToken != NULL)
    {
        if(lToken == NULL) break;
        if(isWhitespace(lToken)){
            lToken = strtok(NULL, " ");
            continue;
        }
        int lRet = GetNumber(lToken, &lServo);
        if( lRet == 0){
            lToken = strtok(NULL, " ");
            continue;
        }
        switch(lToken[0]){
            case 'P':
               {int lValue = atoi(&lToken[1]);
               switch(lServo){
                   case 0:
                       s0 = lValue;
                       break;
                   case 1:
                       s1 = lValue;
                       break;
                   case 2:
                       s2 = lValue;
                       break;
                   case 3:
                       s3 = lValue;
                       break;
                   case 4:
                       s4 = lValue;
                       break;
                   case 5:
                       s5 = lValue;
                       break;
               }
               break;}
            case 'T':
               lTime = atoi(&lToken[1]);
               break;
        }
        lCounter++;
        if(lCounter > 100) break;
        lToken = strtok(NULL, " ");
    }

    QTextStream(stdout) << "Set values readed from M4" << endl;
    data->SolveXYZ(s0,s1,s2,s3,s4,s5);
    QTextStream(stdout) << "Solved z" << data->Z << " x"<<data->X<< " a"<< data->angle<< " a2:"<< QString::number(data->angle2) <<endl;
    ui->sldZ->setValue(data->Z);
    ui->sldX->setValue(data->X);
    ui->sldRotar->setValue(data->Y);
    this->rotarText(data->Y);
    ui->sldHand_2->setValue(data->angle);
    ui->lblHand->setText(QString::number(data->angle));
    ui->sldHand->setValue(data->angle2);
    ui->lblHand_2->setText(QString::number((int)data->angle2));
    //data->setTime(QString::number(lTime));
    QTextStream(stdout) << "Solved z" << ui->sldZ->value() << " x"<< ui->sldX->value() << " a"<< ui->sldHand_2->value() << " a2:"<< ui->sldHand->value() <<endl;
    QTextStream(stdout) << "move " << data->moveXYZ()<< endl;//*/
}



