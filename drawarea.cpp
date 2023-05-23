#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>

#include <QPrinter>
#include <QPrintDialog>

#endif

#include "drawarea.h"
#include "roboticarm.h"


DrawArea::DrawArea(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    resizeImage(&image, QSize(1006, 561));
}


void DrawArea::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = drawing = false;
    d = 50;
    for(int i = 0; i < 20000; i++)
        drawnRoute[i] = QPoint(0, 0);
    for(int i = 0; i < d; i++)
        positionPoints[i] = QPoint(0, 0);
    points = pointsToDraw = pointNumber = 0;
    positionPoints[pointsToDraw++] = QPoint(d, d);
    dx = dy = calculatedDistance = 0.0;
    setPenWidth(4);
    setPenColor(Qt::black);
    drawPoints();
}


void DrawArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !modified) {
        startPoint = drawnRoute[points++] = positionPoints[pointsToDraw++] = event->pos();
        drawing = true;
    }
}


void DrawArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing && !modified){
        drawLineTo(event->pos());
        drawnRoute[points++] = event->pos();
        if(!checkColision(event->pos(), 125))
            positionPoints[pointsToDraw++] = event->pos();
    }
}


void DrawArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing) {
        drawLineTo(event->pos());
        drawnRoute[points] = positionPoints[pointsToDraw] = event->pos();
        drawing = false;
        if((pointsToDraw > 2) && !checkOutOfBounce()){
            modified = true;

            if(checkColision(positionPoints[(pointsToDraw - 1)], (d*2))){
                positionPoints[(pointsToDraw - 1)] = positionPoints[pointsToDraw];
                positionPoints[pointsToDraw--] = QPoint(0, 0);
            }

            if(checkColision(positionPoints[pointsToDraw], (d*2)) || checkColision(positionPoints[1], (d*2))){
                //QMessageBox::warning(this, tr("Collision detected!"), tr("It is impossible to draw this track without collision.\nPlease, start again."), QMessageBox::Ok);
                clearImage();
                return;
            }
            drawPoints();
            const char *fileFormat = "png";
            QString initialPath = QDir::currentPath() + "/drawGame." + fileFormat;
            saveImage(initialPath, fileFormat);
            QApplication::processEvents();
            emit trackChanged();
            clearImage();
        }
        else {
            //QMessageBox::warning(this, tr("Not enough points do draw!"), tr("It is impossible to draw this track.\nPlease, add more points and start again."), QMessageBox::Ok);
            clearImage();
        }
    }
}


void DrawArea::drawPoints(){
    image.fill(qRgb(255, 255, 255));

    QPainter painter(&image);
    painter.setFont(QFont("Arial", 16, QFont::Normal));

    if(modified){
        painter.setBrush(QColor(85, 153, 255));

        /*for(unsigned int i = 0; i < pointsToDraw; i++){
            painter.setPen(QPen(Qt::black, 4));
            painter.drawLine(positionPoints[i], positionPoints[i+1]);
        }*/

        for(unsigned int i = 0; i < points; i++){
            painter.setPen(QPen(Qt::black, 4));
            //painter.drawLine(drawnRoute[i], drawnRoute[i+1]);
            painter.drawPolyline(drawnRoute, points);
            //painter.drawPolygon(drawnRoute, points);
        }

        //QSplineSeries *series = new QSplineSeries();

        /*for(unsigned int i = 0; i < points; i++){
                    *series << drawnRoute[i];
                }

        for(unsigned int i = 0; i < points; i++){
            *series << drawnRoute[i];
        }*/

        for(unsigned int i = 1; i < pointsToDraw; i++){
                pointNumber++;
                painter.setPen(QPen(Qt::black, 1));
                painter.drawEllipse(positionPoints[i], d, d);
                if(i < 10)
                    painter.drawText(positionPoints[i].x() - 6, positionPoints[i].y() + 7, QString::number(pointNumber));
                else
                    painter.drawText(positionPoints[i].x() - 11, positionPoints[i].y() + 7, QString::number(pointNumber));
        }
        painter.setBrush(QColor(0, 255, 0));
        painter.drawEllipse(positionPoints[pointsToDraw], d, d);
        painter.drawText(positionPoints[pointsToDraw].x() - 27, positionPoints[pointsToDraw].y() + 7, "Home");
    }
    else {
        painter.drawText(270, 27, "Do not draw outside rectangle or close to Ready point!");
        painter.drawRect(QRect(d, d, (size().width() - (d * 2)), (size().height() - (d * 2))));
    }

    painter.setBrush(QColor(255, 255, 0));
    painter.drawEllipse(positionPoints[0], d, d);
    painter.drawText((positionPoints[0].x() - 29), (positionPoints[0].y() + 7), "Ready");

    update();
}


bool DrawArea::checkColision(const QPoint &point, int distance){
    for(unsigned int i = 0; i <= pointsToDraw; i++){
        if(point != positionPoints[i]){
            dx = abs(positionPoints[i].x() - point.x());
            dy = abs(positionPoints[i].y() - point.y());
            calculatedDistance = sqrt(pow(dx, 2) + pow(dy, 2));

            if(calculatedDistance < distance)
                return true;
        }
    }
    return false;
}


bool DrawArea::checkOutOfBounce(){
    for(unsigned int i = 0; i <= points; i++){
        if(drawnRoute[i].x() < d || drawnRoute[i].x() > (size().width() - d))
            return true;
        if(drawnRoute[i].y() < d || drawnRoute[i].y() > (size().height() - d))
            return true;
    }
    return false;
}


bool DrawArea::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    } else {
        return false;
    }
}


void DrawArea::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}


void DrawArea::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}


void DrawArea::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(startPoint, endPoint);

    int rad = (myPenWidth / 2) + 2;
    update(QRect(startPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    startPoint = endPoint;
}


void DrawArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);

    update();
}


void DrawArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
    clearImage();
}


void DrawArea::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}
