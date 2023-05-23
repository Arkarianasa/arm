#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
//#include <QtCharts>

//using namespace QtCharts;

class DrawArea : public QWidget
{
    Q_OBJECT

public:
    DrawArea(QWidget *parent = 0);

    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }
    bool getModified(){ return modified; }
    QPoint* getPositionPoints() { return positionPoints; }
    QPoint *positionPoints = new QPoint[50];

public slots:
    void clearImage();
    void drawPoints();
    bool checkColision(const QPoint &point, int distance);
    bool checkOutOfBounce();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

signals:
    void trackChanged();

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified;
    bool drawing;
    int myPenWidth;
    int d;
    unsigned int points;
    unsigned int pointsToDraw;
    unsigned int pointNumber;
    double dx;
    double dy;
    double calculatedDistance;
    QColor myPenColor;
    QImage image;
    QPoint startPoint;

    QPoint *drawnRoute = new QPoint[20000];
};

#endif
