#include "game2.h"
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */

Game2::Game2(QWidget *parent) : QThread(parent)
{
    autoPlay = 0;
}

void Game2::run(){
    emit game2_start();
    this->Play();
    emit game2_end();
}

void Game2::init(SendData* d, int s, int t, int a, QString defaultPath){
    cube = new MyGraphicsView();
    this->defaultPath = defaultPath;
    int i;
    char buffer[200];
    this->filePath = this->defaultPath + "/GamePositions";
    int fd = open(this->filePath.toStdString().c_str(),O_RDWR);
    if (fd != -1)
    {
        read(fd,&buffer,200);
    }
    QString buf(buffer);
    QStringList pieces = buf.split('\n');

    for(i=0; i<pieces.count(); i++){
        QStringList P = pieces.value(i).split(';');
        if(pieces.value(i).count()){
            CalibratingPositions[i].setX(P.value(0).toInt());
            CalibratingPositions[i].setY(P.value(1).toInt());
            CalibratingPositions[i].setZ(P.value(2).toInt());
        }
    }

    this->data = d;
    this->speed = s;
    this->touch = -10;
    this->angle = a;
    data->setTime(speed);
    this->num = 0;
    this->setFirstPos(GAME2_FPOS_X,GAME2_FPOS_Y,GAME2_FPOS_Z);
    this->setFreePos(GAME2_FRPOS_X,GAME2_FRPOS_Y,GAME2_FRPOS_Z);
}


void Game2::load(){
    int i;
    char buffer[200];
    this->filePath = this->defaultPath + "/GamePositions";
    int fd = open(this->filePath.toStdString().c_str(),O_RDWR);
    if (fd != -1)
    {
        read(fd,&buffer,200);
    }
    QString buf(buffer);
    QStringList pieces = buf.split('\n');

    for(i=0; i<pieces.count(); i++){
        QStringList P = pieces.value(i).split(';');
        if(pieces.value(i).count()){
            CalibratingPositions[i].setX(P.value(0).toInt());
            CalibratingPositions[i].setY(P.value(1).toInt());
            CalibratingPositions[i].setZ(P.value(2).toInt());
        }
    }
    close(fd);
}

void Game2::save(){
    char buffer[200];
    int i;
    for(i=0; i<sizeof(CalibratingPositions)/sizeof(CalibratingPositions[0] ); i++){
        if(i==0){
            sprintf(buffer,"%d;%d;%d;",(int)CalibratingPositions[i].x(),(int)CalibratingPositions[i].y(),(int)CalibratingPositions[i].z());
        }else{
            sprintf(buffer,"%s\n%d;%d;%d;",buffer,(int)CalibratingPositions[i].x(),(int)CalibratingPositions[i].y(),(int)CalibratingPositions[i].z());
        }
    }
    this->filePath = this->defaultPath + "/GamePositions";
    int fd = open(this->filePath.toStdString().c_str(),O_RDWR);
    write(fd,&buffer,strlen(buffer));
}

MyGraphicsView* Game2::getCube(){
    return cube;
}

void Game2::setFirstPos(int x, int y, int z){

    firstPos.setX(x);
    firstPos.setY(y);
    firstPos.setZ(z);


    lastPos.setX(this->firstPos.x()+CalibratingPositions[0].x());
    lastPos.setY(this->firstPos.y()+CalibratingPositions[0].y());
    lastPos.setZ(this->firstPos.z()+CalibratingPositions[0].z());
}

void Game2::setFreePos(int x, int y, int z){
    freePos.setX(x);
    freePos.setY(y);
    freePos.setZ(z);
}

void Game2::setPosition(int p){
    //load();
    this->num = p;
    if((this->num) <= 13){
        this->start();
        if(this->num==13){
            emit game_error(GAME2_ERROR_END);
        }else{
            emit game_error(GAME2_ERROR_NO);
        }
    }else{
        emit game_error(GAME2_ERROR_MAX_NUM);
    }
}

void Game2::Shuffle(){
    //load();
    int  cc;
    cc = rand()%6 + 1;
    cube->cube(cc);
    if((this->num + cc) <= 13){
        this->num += cc;
        this->start();
        if(this->num==13){
            emit game_error(GAME2_ERROR_END);
        }else{
            emit game_error(GAME2_ERROR_NO);
        }
    }else{
        emit game_error(GAME2_ERROR_MAX_NUM);
    }
}

void Game2::Dice(int cc){
    cube->cube(cc);
    if((this->num + cc) <= 13){
        this->num += cc;
        this->start();
        if(this->num==13){
            emit game_error(GAME2_ERROR_END);
        }else{
            emit game_error(GAME2_ERROR_NO);
        }
    }else{
        emit game_error(GAME2_ERROR_MAX_NUM);
    }
}

void Game2::Next(){
    //load();
    this->num++;
    cube->cube(num);
    this->start();
}

void Game2::ChangeGame(){

}

void Game2::Home(){
    load();
    this->num = 0;
    cube->clear();
    emit game_error(GAME2_ERROR_NO);
    this->start();
}

void Game2::Play(){
    QVector3D P_put;
    if(num < 14 && num >= 0){
        P_put.setX(this->firstPos.x()+CalibratingPositions[num].x());
        P_put.setY(this->firstPos.y()+CalibratingPositions[num].y());
        P_put.setZ(this->firstPos.z()+CalibratingPositions[num].z());
    }
    /*switch(num){
        case 1:
            P_put.setX(this->firstPos.x()-5);
            P_put.setY(this->firstPos.y()-20);
            P_put.setZ(this->firstPos.z()-5);
            break;
        case 2:
            P_put.setX(this->firstPos.x()-30);
            P_put.setY(this->firstPos.y()-32);
            P_put.setZ(this->firstPos.z()-3);
            break;
        case 3:
            P_put.setX(this->firstPos.x()-30);
            P_put.setY(this->firstPos.y()-53);
            P_put.setZ(this->firstPos.z());
            break;
        case 4:
            P_put.setX(this->firstPos.x()-25);
            P_put.setY(this->firstPos.y()-74);
            P_put.setZ(this->firstPos.z());
            break;
        case 5:
            P_put.setX(this->firstPos.x()-3);
            P_put.setY(this->firstPos.y()-87);
            P_put.setZ(this->firstPos.z()-3);
            break;
        case 6:
            P_put.setX(this->firstPos.x()+29);
            P_put.setY(this->firstPos.y()-89);
            P_put.setZ(this->firstPos.z()-5);
            break;
        case 7:
            P_put.setX(this->firstPos.x()+45);  //-5
            P_put.setY(this->firstPos.y()-77);
            P_put.setZ(this->firstPos.z()-5);
            break;
        case 8:
            P_put.setX(this->firstPos.x()+48);
            P_put.setY(this->firstPos.y()-65);
            P_put.setZ(this->firstPos.z()-5);
            break;
        case 9:
            P_put.setX(this->firstPos.x()+48);
            P_put.setY(this->firstPos.y()-53);
            P_put.setZ(this->firstPos.z()-8);
            break;
        case 10:
            P_put.setX(this->firstPos.x()+50);
            P_put.setY(this->firstPos.y()-42);
            P_put.setZ(this->firstPos.z()-9);
            break;
        case 11:
            P_put.setX(this->firstPos.x()+48);
            P_put.setY(this->firstPos.y()-29);
            P_put.setZ(this->firstPos.z()-8);
            break;
        case 12:
            P_put.setX(this->firstPos.x()+30);
            P_put.setY(this->firstPos.y()-18);
            P_put.setZ(this->firstPos.z()-5);
            break;
        case 13:
            P_put.setX(this->firstPos.x()+9);
            P_put.setY(this->firstPos.y()-37);
            P_put.setZ(this->firstPos.z()-3);
            break;
        case 0:
            P_put.setX(this->firstPos.x()-6);
            P_put.setY(this->firstPos.y());
            P_put.setZ(this->firstPos.z());
            break;
    }*/

    if(num >=0 && num <= 13){

        Move(lastPos, 1);
        Move(freePos, 0);
        Move(P_put, 2);
        Move(freePos, 0);

        lastPos = P_put;
    }
}

void Game2::Move(QVector3D p, int pick){
    //load();
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
void Game2::AutoPlay(){
    if(this->autoPlay == 1){
        this->autoPlay = 0;
    }else{
        this->autoPlay = 1;
        this->Shuffle();
    }
}

void Game2::cube_set(int num){
    cube->cube(num);
}

Game2::~Game2()
{
    this->quit();
    this->wait();
}
