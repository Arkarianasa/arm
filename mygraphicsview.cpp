#include "mygraphicsview.h"
#include <QMouseEvent>
#include <QIODevice>
#include <QTouchEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QString>
#include <QTransform>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <QTextStream>
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */


using namespace cv;

struct coordinates_t {
  int x, y;
} coord[14];

MyGraphicsView::MyGraphicsView(QWidget *parent) :
    QGraphicsScene(parent)
{
    //graphical touch positions on pitch
    coord[0].x = 13;
    coord[0].y = 13;

    coord[1].x = 115; //98;
    coord[1].y = 115; //98;

    coord[2].x = 241; //202;
    coord[2].y = 61; //53;

    coord[3].x = 373; //313;
    coord[3].y = 49; //43;

    coord[4].x = 505; //423;
    coord[4].y = 67; //58;

    coord[5].x = 631; //528;
    coord[5].y = 121; //103;

    coord[6].x = 709; //592;
    coord[6].y = 235; //197;

    coord[7].x = 631; //528;
    coord[7].y = 337; //282;

    coord[8].x = 505; //423;
    coord[8].y = 391; //328;

    coord[9].x = 373; //313;
    coord[9].y = 409; //342;

    coord[10].x = 241; //202;
    coord[10].y = 397; //332;

    coord[11].x = 115; //98;
    coord[11].y = 355; //297;

    coord[12].x = 37; //32;
    coord[12].y = 229; //192;

    coord[13].x = 223; //187;
    coord[13].y = 229; //192;
}

void MyGraphicsView::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QPointF pt = event->scenePos();
    double x,y;
    //QString qStr = QString::number(event->scenePos().x()) + " x " + QString::number(event->scenePos().y());
    //this->addText(qStr);

    //this->cross(pt.x(),pt.y());
    if(event->buttons() == Qt::LeftButton && mode == POSITION_MODE)
    {
        x = pt.x()/((this->gwW+100)/this->sldXM);
        y = pt.y()/((this->gwH+100)/this->sldYM);
        y = (this->sldYM) - y;
        x = (this->sldXM) - x;

        //this->crossX(x,y);
        this->X = x/10;
        this->Y = y/10;
        emit newPos();
    }
    if(event->buttons() == Qt::LeftButton && mode == GAME2_MODE)
    {
        //QString qStr = QString::number(pt.x()) + " x " + QString::number(pt.y());
        //this->addText(qStr);
        for(int i=0; i<sizeof( coord ) / sizeof( coord[0] ); i++){
            if(pt.x() > coord[i].x && pt.x() < (coord[i].x+75) && pt.y() > coord[i].y && pt.y() < (coord[i].y+75))
            {
                emit clicked_pitch(i);
            }
        }


    }
    event->accept();
}

void MyGraphicsView::showImage(cv::Mat image){
    //cv::Mat destination;// = cvCreateImage ( cv::Size(100 , 100), image.depth(), image.channels() );
    cv::resize(image, image, cv::Size(160,120));

    qImage = QImage((const uchar*)image.ptr(), image.cols, image.rows, QImage::Format_RGB888).rgbSwapped();
    pixmap = QPixmap::fromImage(qImage);

    this->clear();
    this->addPixmap(pixmap);
}

void MyGraphicsView::cross(double x, double y){
    //this->clear();
    this->addLine((x-5),y,(x+5),y);
    this->addLine(x,(y-5),x,(y+5));
}

void MyGraphicsView::crossX(double x, double y){
    char buf[20];
    sprintf(buf,"x=%.2f, y=%.2f",x,y);
    x=x*10;
    y=y*20;
    this->addText(buf);
    x = x * ((this->gwW)/this->sldXM);
    y = y * ((this->gwH)/this->sldYM);
    y = (this->gwH-5) - y+5;
    x = (this->gwW-5) - x+5;

    //this->clear();
    this->addLine((x-5),y,(x+5),y);
    this->addLine(x,(y-5),x,(y+5));
}

void MyGraphicsView::DrawPict(QString path, float x, float y, float x1, float y1, int g){
    x=x*10;
    y=y*20;
    x1=x1*10;
    y1=y1*20;
    float angle;
    x=convertCoord(x,'x');
    y=convertCoord(y,'y');
    x1=convertCoord(x1,'x');
    y1=convertCoord(y1,'y');
    /* x=x*10;
     y=y*10;
     x1=x1*10;
     y1=y1*10;*/
    if((x-x1) == 0){
        angle = 90;
    }else{
        angle = atan((y-y1)/(x-x1)) * (180 / M_PI);
    }
    if(angle == 90 && g == 3){
        angle += 180;
        float ax = x;
        float ay = y;
        x = x1;
        y = y1;
        x1=ax;
        y1=ay;
    }
    //sprintf(buf,"a=%.2f",angle);
   // this->addText(buf);
    QPixmap ImagePixmap1;
    ImagePixmap1.load(path);
    QTransform transform;
    QTransform trans = transform.rotate(angle);
    QPixmap transPixmap = QPixmap(ImagePixmap1.transformed(trans));
    QGraphicsPixmapItem *pixmapItem1 = this->addPixmap(transPixmap);
    if(angle<0 && (g == 2 || g == 3)){
        y = y1;
    }
    if(angle<0 && g == 1){
        x = x1;
    }
    if(g==0){
        pixmapItem1->setX(x);
        pixmapItem1->setY(y);
    }else{
        pixmapItem1->setX(x-ImagePixmap1.height()/2);
        pixmapItem1->setY(y-ImagePixmap1.height()/2);
    }
}

void MyGraphicsView::addLineReal(double x, double y, double x1, double y1, char color){
    QPen p;
    x=x*10;
    y=y*20;
    x1=x1*10;
    y1=y1*20;
    switch (color){
        case 'b':
            p.setColor(Qt::blue);
            break;
        case 'r':
            p.setColor(Qt::red);
            break;
    }
    p.setWidth(3);

    this->addLine(convertCoord(x,'x'),convertCoord(y,'y'),convertCoord(x1,'x'),convertCoord(y1,'y'),p);
}

int MyGraphicsView::convertCoord(double i, char c){
    //i=i*10;
    switch (c){
        case 'x': //x
            i = i*((this->gwW+10)/this->sldXM);
            i = (this->gwW) - i;
            break;
        case 'y': //y
            i = i*((this->gwH+10)/this->sldYM);
            i = (this->gwH) - i;
            break;

    }
    return i;
}

void MyGraphicsView::cube(int num){
    this->clear(); //tuna to padlo, SIGNAL Aborted
    switch(num){
        case 1:
            this->addEllipse(this->gwW/2,this->gwH/2,10,10,QPen(Qt::blue,3));
            break;
        case 2:
            this->addEllipse(this->gwW/3,this->gwH/3,10,10,QPen(Qt::blue,3));
            this->addEllipse(2*(this->gwW/3),2*(this->gwH/3),10,10,QPen(Qt::blue,3));
            break;
        case 3:
            this->addEllipse(this->gwW/4,this->gwH/4,10,10,QPen(Qt::blue,3));
            this->addEllipse(3*(this->gwW/4),3*(this->gwH/4),10,10,QPen(Qt::blue,3));
            this->addEllipse(this->gwW/2,this->gwH/2,10,10,QPen(Qt::blue,3));
            break;
        case 4:
            this->addEllipse(this->gwW/3,this->gwH/3,10,10,QPen(Qt::blue,3));
            this->addEllipse((this->gwW/3),2*(this->gwH/3),10,10,QPen(Qt::blue,3));
            this->addEllipse(2*(this->gwW/3),(this->gwH/3),10,10,QPen(Qt::blue,3));
            this->addEllipse(2*(this->gwW/3),2*(this->gwH/3),10,10,QPen(Qt::blue,3));
            break;
        case 5:
            this->addEllipse(this->gwW/4,this->gwH/4,10,10,QPen(Qt::blue,3));
            this->addEllipse(3*(this->gwW/4),3*(this->gwH/4),10,10,QPen(Qt::blue,3));
            this->addEllipse(this->gwW/2,this->gwH/2,10,10,QPen(Qt::blue,3));
            this->addEllipse((this->gwW/4),3*(this->gwH/4),10,10,QPen(Qt::blue,3));
            this->addEllipse(3*(this->gwW/4),(this->gwH/4),10,10,QPen(Qt::blue,3));
            break;
        case 6:
            this->addEllipse(this->gwW/3,this->gwH/4,10,10,QPen(Qt::blue,3));
            this->addEllipse(2*(this->gwW/3),this->gwH/4,10,10,QPen(Qt::blue,3));
            this->addEllipse(this->gwW/3,2*(this->gwH/4),10,10,QPen(Qt::blue,3));
            this->addEllipse(2*(this->gwW/3),2*(this->gwH/4),10,10,QPen(Qt::blue,3));
            this->addEllipse(this->gwW/3,3*(this->gwH/4),10,10,QPen(Qt::blue,3));
            this->addEllipse(2*(this->gwW/3),3*(this->gwH/4),10,10,QPen(Qt::blue,3));
            break;
    }
}

void MyGraphicsView::setScene(int width, int height){
    this->setSceneRect(0,0,width,height);
}

void MyGraphicsView::initPitch(QString path){
    ImagePixmap_game;
    ImagePixmap_game.load(path);
}

void MyGraphicsView::showFigure(int position){
    this->addPixmap(ImagePixmap_game);
    switch(position){
        case 0:
            this->addEllipse(13,13,95,95,QPen(Qt::red,7)); //ready
            break;
        case 1:
            this->addEllipse(115,115,95,95,QPen(Qt::red,6));   //1
            break;
        case 2:
            this->addEllipse(241,61,95,95,QPen(Qt::red,6));    //2
            break;
        case 3:
            this->addEllipse(373,49,95,95,QPen(Qt::red,6));    //3
            break;
        case 4:
            this->addEllipse(505,67,95,95,QPen(Qt::red,6));    //4
            break;
        case 5:
            this->addEllipse(631,121,95,95,QPen(Qt::red,6));    //5
            break;
        case 6:
            this->addEllipse(709,235,95,95,QPen(Qt::red,6));    //6
            break;
        case 7:
            this->addEllipse(631,337,95,95,QPen(Qt::red,6));    //7
            break;
        case 8:
            this->addEllipse(505,391,95,95,QPen(Qt::red,6));    //8
            break;
        case 9:
            this->addEllipse(373,409,95,95,QPen(Qt::red,6));    //9
            break;
        case 10:
            this->addEllipse(241,397,95,95,QPen(Qt::red,6));    //10
            break;
        case 11:
            this->addEllipse(115,355,95,95,QPen(Qt::red,6));    //11
            break;
        case 12:
            this->addEllipse(37,229,95,95,QPen(Qt::red,6));    //12
            break;
        case 13:
            this->addEllipse(223,229,95,95,QPen(Qt::red,7));    //home
            break;
    }
}


void MyGraphicsView::showFigureDynamic(int position){
    this->loadPoints("/home/udooer/Desktop/RoboticArm");

    this->addPixmap(ImagePixmap_game);

    this->addEllipse(positionPoints[position].x()-46,positionPoints[position].y()-46,93,93,QPen(Qt::red,7));
}


void MyGraphicsView::savePoints(QString defaultPath){
    path = defaultPath + "/DrawGamePositions";
    char buffer[1000];

    for(int i = 0; i < 50; i++){
        if(i == 0  && positionPoints[i].x() != 0 && positionPoints[i].y() != 0) {
            sprintf(buffer,"%d;%d;", positionPoints[i].x(), positionPoints[i].y());
            QTextStream(stdout) << i << ". saved point: " << positionPoints[i].x() << ", " << positionPoints[i].y() << endl;
        }
        else if (positionPoints[i].x() != 0 && positionPoints[i].y() != 0) {
            sprintf(buffer,"%s\n%d;%d;", buffer, positionPoints[i].x(), positionPoints[i].y());
            //QTextStream(stdout) << i << ". saved point: " << positionPoints[i].x() << ", " << positionPoints[i].y() << endl;
        }
    }

    int fd = open (path.toStdString().c_str(), O_TRUNC|O_WRONLY);
    if ( fd >= 0 )
        close(fd);

    //fd = open(path.toStdString().c_str(), O_CREAT|O_RDWR);
    fd = open(path.toStdString().c_str(), O_CREAT|O_RDWR, 0644);

    write(fd, &buffer, strlen(buffer));
    if ( fd >= 0 )
        close(fd);
}


void MyGraphicsView::loadPoints(QString defaultPath){
    for(int i = 0; i < 50; i++)
        positionPoints[i] = QPoint(0, 0);

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
            positionPoints[i] = QPoint(P.value(0).toInt(), P.value(1).toInt());
            //QTextStream(stdout) << i << ". loaded point: " << positionPoints[i].x() << ", " << positionPoints[i].y() << endl;
        }
    }
    close(fd);
}
