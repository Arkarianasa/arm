#include "game.h"
#include <unistd.h>
#include "roboticarm.h"
#include <QThread>

Game::Game(QWidget *parent) : QThread(parent)
{


}

void Game::run(){
    this->Play();
}

void Game::init(SendData* d, int s, int t, int a){
    cube = new MyGraphicsView();
    this->data = d;
    this->speed = s;
    this->touch = t;
    this->angle = a;
    data->setTime(speed);
}

void Game::setSpeed(int s){
    this->speed = s;
}
void Game::setTouch(int t){
    this->touch = t;
}
void Game::setAngle(int a){
    this->angle = a;
}

void Game::setFirstPos(int x, int y, int z){

    firstPos.setX(x);
    firstPos.setY(y);
    firstPos.setZ(z);


    lastPos.setX(x);
    lastPos.setY(y);
    lastPos.setZ(z);
}

void Game::setFreePos(int x, int y, int z){
    freePos.setX(x);
    freePos.setY(y);
    freePos.setZ(z);
}

MyGraphicsView* Game::getCube(){
    return cube;
}

void Game::GoStart(){
    lastPos = firstPos;
}

void Game::Go1(){
    num = 1;
    cube->cube(num);
    this->start();
}

void Game::Go2(){
    num = 2;
    cube->cube(num);
    this->start();
}

void Game::Go3(){
    num = 3;
    cube->cube(num);
    this->start();
}

void Game::Go4(){
    num = 4;
    cube->cube(num);
    this->start();
}

void Game::Go5(){
    num = 5;
    cube->cube(num);
    this->start();
}

void Game::Go6(){
    num = 6;
    cube->cube(num);
    this->start();
}

void Game::Shuffle(){
    this->num = rand()%6 + 1;
    cube->cube(num);
    //timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(Play()));
    //timer->start(100);
    this->start();
}

void Game::Play(){
    QVector3D P_put;
    //timer->stop();
    switch(num){
        case 1:
            P_put.setX(this->firstPos.x()+20);
            P_put.setY(this->firstPos.y()-53);
            P_put.setZ(this->firstPos.z());
            break;
        case 2:
            P_put.setX(this->firstPos.x()+10);
            P_put.setY(this->firstPos.y()-90);
            P_put.setZ(this->firstPos.z());
            break;
        case 3:
            P_put.setX(this->firstPos.x()+10);
            P_put.setY(this->firstPos.y()-128);
            P_put.setZ(this->firstPos.z());
            break;
        case 4:
            P_put.setX(this->firstPos.x()+70);
            P_put.setY(this->firstPos.y()-62);
            P_put.setZ(this->firstPos.z());
            break;
        case 5:
            P_put.setX(this->firstPos.x()+60);
            P_put.setY(this->firstPos.y()-90);
            P_put.setZ(this->firstPos.z());
            break;
        case 6:
            P_put.setX(this->firstPos.x()+60);
            P_put.setY(this->firstPos.y()-115);
            P_put.setZ(this->firstPos.z());
            break;
    }

    Move(lastPos, 1);
    Move(freePos, 0);
    Move(P_put, 2);
    Move(freePos, 0);

    lastPos = P_put;
    emit this->Play_done();

}

void Game::Move(QVector3D p, int pick){
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
        if(pick==2){
            data->SolveCoordinates(p.x(),0,p.z(),this->angle);
        }else{
            data->SolveCoordinates(p.x(),0,p.z(),this->angle);
        }
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

Game::~Game()
{
    this->quit();
    this->wait();
}
