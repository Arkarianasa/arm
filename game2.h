#ifndef GAME2_H
#define GAME2_H

#include <QWidget>
#include <QThread>
#include <QVector3D>
#include <termios.h>
#include "mygraphicsview.h"
#include "senddata.h"

#define TOUCH_MAX 40

/* GAME 2 */
#define GAME2_SPEED  1500
#define GAME2_ANGLE  -90    //79
#define GAME2_TOUCH  -10

#define GAME2_FPOS_X 78 //72 //89
#define GAME2_FPOS_Y 112 //132   //134
#define GAME2_FPOS_Z 60 //68

#define GAME2_FRPOS_X 50
#define GAME2_FRPOS_Y 70
#define GAME2_FRPOS_Z 100

/* errors */
#define GAME2_ERROR_MAX_NUM 5
#define GAME2_ERROR_NO      0
#define GAME2_ERROR_END     6

class Game2 : public QThread
{
    Q_OBJECT
public:
    explicit Game2(QWidget *parent = 0);
    void init(SendData* d, int s, int t, int a, QString defaultPath);
    MyGraphicsView* getCube();
    void Move(QVector3D p, int pick);
    void setFirstPos(int x, int y, int z);
    void setFreePos(int x, int y, int z);
    ~Game2();
    void cube_set(int num);
    void load();
    void save();
    int num;
    int autoPlay;
    QVector3D CalibratingPositions[14];
    QVector3D lastPos, freePos, firstPos;

signals:
    void game_error(int e);
    void game2_start();
    void game2_end();

public slots:
    void Shuffle();
    void Play();
    void Next();
    void Home();
    void ChangeGame();
    void setPosition(int p);
    void AutoPlay();
    void Dice(int cc);

private:
    MyGraphicsView* cube;
    SendData* data;
    int speed, touch, angle;
    QString defaultPath, filePath;


protected:
    void run();
};

#endif // GAME2_H
