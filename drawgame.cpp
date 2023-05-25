#include "drawgame.h"
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <math.h>
#include <QTextStream>
#include <time.h>

DrawGame::DrawGame(QWidget *parent) : QThread(parent)
{
    autoPlay = 0;
}

void DrawGame::run(){
    emit drawGame_start();
    this->Play();
    emit drawGame_end();
}

void DrawGame::init(SendData* d, int s, int t, int a, QString defaultPath){
    cube = new MyGraphicsView();
    this->defaultPath = defaultPath;
    this->loadPoints(defaultPath);

    srand(time(NULL));
    this->data = d;
    this->speed = s;
    this->touch = -10;
    this->angle = a;
    data->setTime(speed);
    this->num = 0;
    this->setFirstPos(DRAWGAME_FPOS_X,DRAWGAME_FPOS_Y,DRAWGAME_FPOS_Z);
    this->setFreePos(DRAWGAME_FRPOS_X,DRAWGAME_FRPOS_Y,DRAWGAME_FRPOS_Z);
}


void DrawGame::load(){
    this->pointsCount = 0;
    int i;
    char buffer[1000];
    this->filePath = this->defaultPath + "/DrawGamePositions";
    int fd = open(this->filePath.toStdString().c_str(),O_RDWR);
    if (fd != -1)
    {
        read(fd,&buffer,200);
    }
    QString buf(buffer);
    QStringList pieces = buf.split('\n');

    for(i=0; i<pieces.count(); i++){
        this->pointsCount++;
        QStringList P = pieces.value(i).split(';');
        if(pieces.value(i).count()){
            CalibratingPositions[i].setX(P.value(0).toInt());
            CalibratingPositions[i].setY(P.value(1).toInt());
            CalibratingPositions[i].setZ(P.value(2).toInt());
            QTextStream(stdout) << i << ". calibration point: " << CalibratingPositions[i].x() << ", " << CalibratingPositions[i].y() << ", "  << CalibratingPositions[i].z() << endl;
        }
    }
    QTextStream(stdout) << this->pointsCount << endl;
    close(fd);
}

void DrawGame::save(){
    char buffer[200];
    int i;
    for(i=0; i<sizeof(CalibratingPositions)/sizeof(CalibratingPositions[0] ); i++){
        if(i==0){
            sprintf(buffer,"%d;%d;%d;",(int)CalibratingPositions[i].x(),(int)CalibratingPositions[i].y(),(int)CalibratingPositions[i].z());
        }else{
            sprintf(buffer,"%s\n%d;%d;%d;",buffer,(int)CalibratingPositions[i].x(),(int)CalibratingPositions[i].y(),(int)CalibratingPositions[i].z());
        }
    }
    this->filePath = this->defaultPath + "/GamePositions2";
    int fd = open(this->filePath.toStdString().c_str(),O_RDWR);
    write(fd,&buffer,strlen(buffer));
}

MyGraphicsView* DrawGame::getCube(){
    return cube;
}

void DrawGame::setFirstPos(int x, int y, int z){

    firstPos.setX(x);
    firstPos.setY(y);
    firstPos.setZ(z);

    lastPos.setX(this->firstPos.x()+CalibratingPositions[0].x());
    lastPos.setY(this->firstPos.y()+CalibratingPositions[0].y());
    lastPos.setZ(this->firstPos.z()+CalibratingPositions[0].z());
}

void DrawGame::setFreePos(int x, int y, int z){
    freePos.setX(x);
    freePos.setY(y);
    freePos.setZ(z);
}

void DrawGame::setPosition(int p){
    this->num = p;
    if((this->num) <= (this->pointsCount - 1)){
        this->start();
        if(this->num==(this->pointsCount - 1)){
            emit drawGame_error(DRAWGAME_ERROR_END);
        }else{
            emit drawGame_error(DRAWGAME_ERROR_NO);
        }
    }else{
        emit drawGame_error(DRAWGAME_ERROR_MAX_NUM);
    }
}

void DrawGame::Shuffle(){
    cc = rand()%6 + 1;
    cube->cube(cc);
    if((this->num + cc) <= (this->pointsCount - 1)){
        this->num += cc;
        this->start();
        if(this->num==(this->pointsCount - 1)){
            emit drawGame_error(DRAWGAME_ERROR_END);
        }else{
            emit drawGame_error(DRAWGAME_ERROR_NO);
        }
    }else{
        emit drawGame_error(DRAWGAME_ERROR_MAX_NUM);
    }
}

void DrawGame::Dice(int cc){
    cube->cube(cc);
    if((this->num + cc) <= (this->pointsCount - 1)){
        this->num += cc;
        this->start();
        if(this->num==(this->pointsCount - 1)){
            emit drawGame_error(DRAWGAME_ERROR_END);
        }else{
            emit drawGame_error(DRAWGAME_ERROR_NO);
        }
    }else{
        emit drawGame_error(DRAWGAME_ERROR_MAX_NUM);
    }
}

void DrawGame::Next(){
    this->num++;
    cube->cube(num);
    this->start();
}

void DrawGame::ChangeGame(){

}

void DrawGame::Home(){
    this->num = 0;
    cube->clear();
    emit drawGame_error(DRAWGAME_ERROR_NO);
    this->start();
}

void DrawGame::Play(){
    P_put.setX(this->firstPos.x()+CalibratingPositions[num].x());
    P_put.setY(this->firstPos.y()+CalibratingPositions[num].y());
    P_put.setZ(this->firstPos.z()+CalibratingPositions[num].z());
    QTextStream(stdout) << "Calibrating point " << num << ": " << P_put.x() << ", "  << P_put.y() << ", "  << P_put.z() << endl << endl;

    Move(lastPos, 1);
    Move(freePos, 0);
    Move(P_put, 2);
    Move(freePos, 0);

    lastPos = P_put;
}

void DrawGame::Move(QVector3D p, int pick){
    if(pick!=1){
        usleep(this->speed*1000/2);
    }

    /* Hand */
    data->setServo4();
    if(pick==1){
        data->SendAngle(TOUCH_MAX);
        usleep(this->speed*1000);
    }

    if(pick == 0){
        /* Position */
        data->SolveCoordinates(p.x(),0,p.z(),this->angle);
        usleep(this->speed*1000/2);
    }else{
        /* Rotate */
        data->setServo0();
        data->SendAngle(p.y());
        usleep(this->speed*1000);

        /* Position */
        data->SolveCoordinates(p.x(),0,p.z(),this->angle);
        usleep(this->speed*1000);

    }

    /* Hand */
    data->setServo4();
    if(pick==1){
        data->SendAngle(this->touch);
    }else if(pick==2){
        data->SendAngle(TOUCH_MAX);
    }
    usleep(this->speed*1000/2);

}


/* start automatic play ludo */
void DrawGame::AutoPlay(){
    if(this->autoPlay == 1){
        this->autoPlay = 0;
    }else{
        this->autoPlay = 1;
        this->Shuffle();
    }
}

void DrawGame::cube_set(int num){
    cube->cube(num);
}

DrawGame::~DrawGame()
{
    this->quit();
    this->wait();
}


void DrawGame::loadPoints(QString defaultPath){
    for(int i = 0; i < 50; i++)
        this->positionPoints[i] = QPoint(0, 0);

    char buffer[1000];
    path = defaultPath + "/DrawGamePositions";
    int fd = open(path.toStdString().c_str(), O_RDWR);
    if (fd != -1)
    {
        read(fd, &buffer, 500);
    }
    QString buf(buffer);
    QStringList pieces = buf.split('\n');

    for(int i = 0; i < pieces.count(); i++){
        QStringList P = pieces.value(i).split(';');
        if(pieces.value(i).count()){
            this->positionPoints[i] = QPoint(P.value(0).toInt(), P.value(1).toInt());
            //QTextStream(stdout) << P.value(0).toInt() << ", " << P.value(1).toInt() << endl;
        }
    }
    close(fd);

    this->calculatePoints(defaultPath);
}

void DrawGame::calculatePoints(QString defaultPath){
    this->pointsCount = 0;

    for(int i = 0; i < 50; i++){
        if (positionPoints[i].x() != 0 && positionPoints[i].y() != 0){
            dx = ARM_POS_X - ((X_CORRECTION + positionPoints[i].x()) / DPM);
            dy = ARM_POS_Y - ((Y_CORRECTION + positionPoints[i].y()) / DPM);
            d = sqrt(pow(dx, 2) + pow(dy, 2));
            angleA = -(atan(dx/dy) * 180 / M_PI);

            c = round(d) - DRAWGAME_FPOS_X - BASE_ADVANCE;

            alfa = round(angleA);

            z = -(int)((round(d) - ARM_POS_X + BASE_ADVANCE + 10) / 10);

            if(alfa < 0){
                c += 4;
                alfa -= 1;

                if(c > 100){
                    c +=4;
                    z +=12;
                }
                else if(c > 90){
                    c +=4;
                    z +=8;
                }
                else{
                    z += 4;
                }
            }

            QTextStream(stdout) << i << ". pole: " << c << ", " << alfa << ", "  << z << endl;

            CalibratingPositions[i].setX(c);
            CalibratingPositions[i].setY(alfa);
            CalibratingPositions[i].setZ(z);
            this->pointsCount++;
        }
    }

    QTextStream(stdout) << "Pocet bodu: " << this->pointsCount << endl;
}
