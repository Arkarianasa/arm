#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget>
#include <gst/gst.h>

class Video : public QWidget
{
    Q_OBJECT
public:
    explicit Video(QWidget *parent = 0);
    void init(char* device);

signals:

public slots:
    void Play();
    void Pause();
    void Check();
private:
    GstElement *bin;
    GstElement *pipeline;
    QTimer *timer;

};

#endif // VIDEO_H
