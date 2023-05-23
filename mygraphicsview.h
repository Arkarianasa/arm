#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QIODevice>
#include <QTouchEvent>
#include <QPoint>

//#include <opencv/cv.h>
//#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "drawarea.h"

#define POSITION_MODE   1
#define GAME2_MODE      2
#define OTHER_MODE      0

class MyGraphicsView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent=0);
    void cross(double x, double y);
    void crossX(double x, double y);
    int convertCoord(double i, char c);
    void addLineReal(double x, double y, double x1, double y1, char color);
    void setScene(int width, int height);
    void cube(int num);
    int gwH, gwW, sldXM, sldYM;
    double X,Y;
    void DrawPict(QString path, float x, float y, float x1, float y1, int g);
    void showImage(cv::Mat image);
    int mode;
    void initPitch(QString path);
    void showFigure(int position);
    void showFigureDynamic(int position);
    void setPoints(QPoint *points) { positionPoints = points; }
    void savePoints(QString defaultPath);
    void loadPoints(QString defaultPath);

signals:
    void newPos();
    int clicked_pitch(int n);

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);


private:
       QGraphicsScene *scene;
       QPoint pt;
       QPixmap pixmap;
       QImage qImage;
       QPixmap ImagePixmap_game;
       DrawArea *drawArea;
       QPoint *positionPoints = new QPoint[50];
       QString path;
};

#endif // MYGRAPHICSVIEW_H
