#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QVector3D>
#include <termios.h>
#include "mygraphicsview.h"
#include "senddata.h"
#include <QTimer>
#include <QThread>

#define TOUCH_MAX 50

#define GAME_SPEED  1500
#define GAME_ANGLE  -90
#define GAME_TOUCH  1

#define GAME_FPOS_X 50
#define GAME_FPOS_Y 178
#define GAME_FPOS_Z 60

#define GAME_FRPOS_X 50
#define GAME_FRPOS_Y 110
#define GAME_FRPOS_Z 100

class Game : public QThread
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = 0);
    MyGraphicsView* getCube();
    void init(SendData* d, int s, int t, int a);
    void Move(QVector3D p, int pick);
    void setSpeed(int s);
    void setTouch(int t);
    void setAngle(int a);
    void setFirstPos(int x, int y, int z);
    void setFreePos(int x, int y, int z);
    ~Game();

signals:
    void Play_done();
public slots:
    void Shuffle();
    void Play();
    void GoStart();
    void Go1();
    void Go2();
    void Go3();
    void Go4();
    void Go5();
    void Go6();

private:
    int num;
    MyGraphicsView* cube;
    SendData* data;
    int speed, touch, angle;
    QVector3D lastPos, freePos, firstPos;
    QTimer *timer ;

protected:
    void run();
};

#endif // GAME_H
