#include "video.h"
#include <QString>
#include <fcntl.h>   /* File control definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <QTimer>

Video::Video(QWidget *parent) :
    QWidget(parent)
{
}

void Video::init(char* device){
    /* GST */

    gst_init (NULL,NULL);
    //bin = gst_pipeline_new ("video-player");
    //g_assert(bin);



    pipeline = gst_parse_launch ("filesrc location=/home/udooer/Desktop/RoboticArm/video.mp4 ! decodebin2 ! mfw_v4lsink disp-width=1280 disp-height=1024 device=/dev/video1", NULL);
    //gst_element_set_state (pipeline, GST_STATE_PLAYING);

   /* GstElement *testSrc = gst_element_factory_make("filesrc", "file-source");
    GstElement *videoOut = gst_element_factory_make("mfw_v4lsink", "video-out");
    GstElement *decoder  = gst_element_factory_make ("decodebin2",  "video-dec");

    g_object_set(G_OBJECT(testSrc), "location", "/home/udooer/Desktop/RoboticArm/video.mp4", NULL);
    g_object_set(G_OBJECT(videoOut), "device", "/dev/video16", NULL);
    //g_object_set(G_OBJECT(videoOut), "disp-width", "1920", NULL);
    //g_object_set(G_OBJECT(videoOut), "disp-height", "1080", NULL);


    gst_bin_add_many(GST_BIN(bin), testSrc, decoder, videoOut, NULL);
    //gst_element_link_many(testSrc, decoder,convert, videoOut, NULL);
    gst_element_link(testSrc,decoder);
    gst_element_link(decoder,videoOut);*/

    //gst_element_set_state(GST_ELEMENT(bin), GST_STATE_PLAYING);


    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(Check()));

}

void Video::Play(){
    pipeline = gst_parse_launch ("filesrc location=/home/udooer/Desktop/RoboticArm/video.mp4 ! decodebin2 ! mfw_v4lsink disp-width=1280 disp-height=1024 device=/dev/video1", NULL);
    gst_element_set_state((pipeline), GST_STATE_PLAYING);
    timer->start(100);
}

void Video::Pause(){
    //gst_element_set_state((pipeline), GST_STATE_PAUSED);
    gst_element_set_state((pipeline), GST_STATE_NULL);
    timer->stop();
}

void Video::Check(){
    GstBus *bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
    if(bus != NULL){
        GstMessage *msg = gst_bus_pop(bus);
        if(msg != NULL){
            if(GST_MESSAGE_TYPE(msg) == GST_MESSAGE_EOS){
                gst_element_set_state((pipeline), GST_STATE_NULL);
                pipeline = gst_parse_launch ("filesrc location=/home/udooer/Desktop/RoboticArm/video.mp4 ! decodebin2 ! mfw_v4lsink disp-width=1280 disp-height=1024 device=/dev/video1", NULL);
                gst_element_set_state((pipeline), GST_STATE_PLAYING);
            }
        }
    }
}
