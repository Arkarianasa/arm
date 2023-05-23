#-------------------------------------------------
#
# Project created by QtCreator 2014-09-22T08:32:04
# tohel je novy
#-------------------------------------------------

QT += core gui
QT += widgets
#QT += charts

#requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport

CONFIG   += console

TARGET = RoboticArm
    target.files = RoboticArm
    target.path = ../Project_RoboticArm/RoboticArm

INSTALLS += target
TEMPLATE = app

SOURCES += main.cpp\
    roboticarm.cpp \
    senddata.cpp \
    mygraphicsview.cpp \
    game.cpp \
    video.cpp \
    game2.cpp \
    camera.cpp \
    drawarea.cpp \
    drawgame.cpp

HEADERS  += \
    roboticarm.h \
    senddata.h \
    mygraphicsview.h \
    game.h \
    video.h \
    game2.h \
    camera.h \
    drawarea.h \
    drawgame.h

FORMS    += roboticarm.ui

DEFINES += QT_NO_VERSION_TAGGING


##QMAKE_RPATHDIR += /opt/poky/1.6.1/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi/usr/lib


#INCLUDEPATH += /opt/poky/1.6.1/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi/usr/include
#INCLUDEPATH += /usr/opencv
##INCLUDEPATH += /opt/poky/1.6.1/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi/usr/lib
##LIBS += -L/usr/local/lib
#LIBS += -L/usr/lib/x86_64-linux-gnu
#LIBS += -L/opt/poky/1.6.1/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi/usr/lib

#INCLUDEPATH += /usr/local/include/opencv4/opencv2
INCLUDEPATH += /usr/include/opencv4

LIBS += -L/usr/lib/x86_64-linux-gnu
LIBS += -L/usr/local/lib
LIBS += -lopencv_highgui
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_ml
LIBS += -lopencv_video

LIBS += -lopencv_videoio

LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
#LIBS += -lopencv_videoio
#LIBS += -lopencv_contrib
#LIBS += -lopencv_legacy
LIBS += -lopencv_flann
#LIBS += -lopencv_nonfree

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += gstreamer-1.0
}