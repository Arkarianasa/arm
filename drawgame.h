#ifndef DRAWGAME_H
#define DRAWGAME_H

#include <QWidget>
#include <QThread>
#include <QVector3D>
#include <termios.h>
#include "mygraphicsview.h"
#include "senddata.h"

#define TOUCH_MAX 40

/* GAME 2 */
#define DRAWGAME_SPEED  1500
#define DRAWGAME_ANGLE  -90
#define DRAWGAME_TOUCH  -10

#define DRAWGAME_FPOS_X 50
#define DRAWGAME_FPOS_Y 70
#define DRAWGAME_FPOS_Z 53

#define DRAWGAME_FRPOS_X 50
#define DRAWGAME_FRPOS_Y 70
#define DRAWGAME_FRPOS_Z 100

#define ARM_POS_X 172
#define ARM_POS_Y -40

#define X_CORRECTION 210
#define Y_CORRECTION 100

#define DPI (1366/(344/25.4))
#define DPM (DPI/25.4)

#define BASE_ADVANCE 32

/* errors */
#define DRAWGAME_ERROR_MAX_NUM 5
#define DRAWGAME_ERROR_NO      0
#define DRAWGAME_ERROR_END     6

class DrawGame : public QThread
{
    Q_OBJECT
public:
    explicit DrawGame(QWidget *parent = 0);
    void init(SendData* d, int s, int t, int a, QString defaultPath);
    MyGraphicsView* getCube();
    void Move(QVector3D p, int pick);
    void setFirstPos(int x, int y, int z);
    void setFreePos(int x, int y, int z);
    ~DrawGame();
    void cube_set(int num);
    void load();
    void save();
    int num, pointsCount;
    int autoPlay;
    QVector3D CalibratingPositions[50];
    QVector3D lastPos, freePos, firstPos;

signals:
    void drawGame_error(int e);
    void drawGame_start();
    void drawGame_end();

public slots:
    void Shuffle();
    void Play();
    void Next();
    void Home();
    void ChangeGame();
    void setPosition(int p);
    void AutoPlay();
    void Dice(int cc);
    void loadPoints(QString defaultPath);
    void calculatePoints(QString defaultPath);

private:
    MyGraphicsView* cube;
    SendData* data;
    int speed, touch, angle, c, alfa, z, cc;
    QString defaultPath, filePath;
    QPoint *positionPoints = new QPoint[50];
    QString path;
    double dx, dy, a, d, angleA;
    QVector3D P_put;


protected:
    void run();
};

#endif // DRAWGAME_H
