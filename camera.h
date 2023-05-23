#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QThread>
#include <QTimer>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <QGraphicsScene>
#include "mygraphicsview.h"

#define DICE_THR 4

class Camera : public QThread
{
    Q_OBJECT
public:
    explicit Camera(QWidget *parent = 0);
    MyGraphicsView* getScene();
    cv::Mat getDice();
    void setMoving(bool m);

signals:
    void dice_find(int);

public slots:
    void Show();
    void dice();
    void Play();
    void Stop();

private:
    QTimer *timer ;
    MyGraphicsView * scene;
    cv::VideoCapture *capture1;
    cv::Mat frame, diceMat;
    cv::Mat canny;
    int num, num_b, num_count;
    bool moving;

protected:

};

#endif // CAMERA_H
