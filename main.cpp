#include <QMainWindow>
#include <QApplication>
#include "roboticarm.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    RoboticArm w;
    w.show();
    return app.exec();
}
