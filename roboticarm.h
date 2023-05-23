#ifndef ROBOTICARM_H
#define ROBOTICARM_H

#include <QMainWindow>
#include <QTimer>
#include "senddata.h"
#include "mygraphicsview.h"
#include "game.h"
#include "game2.h"
#include "video.h"
#include "camera.h"
#include "drawgame.h"


namespace Ui {
class RoboticArm;
}

class RoboticArm : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoboticArm(QWidget *parent = 0);
    void visualiseArm();
    void visualiseBorder();
    void SortValues(char *lBuffer);
    ~RoboticArm();
    SendData* data;
    Game* game;
    Game2* game2;
    MyGraphicsView* scene;
    MyGraphicsView *draw;
    DrawGame* drawingGame;
    void initCam();

public slots:
    void printError(int e);
    void setSld();
    void DrawMove();
    void handText(int i);
    void rotarText(int i);
    void diceShow(int num);
    void gameStart();
    void gameEnd();
    void timerTimeout();
    void AutoPlay();
    void SetAsPosition();
    void drawGame();
    void reloadTrack();
    void cancel();
    void setButtonsDrawGame(bool value);
    void calibrateArm();

private:
    Ui::RoboticArm *ui;
    MyGraphicsView* pitch;
    QTimer *timer;
    Camera *cam;
    int dice_b, dice_drawGame;
    QString defaultPath, path;
};

#endif // ROBOTICARM_H
