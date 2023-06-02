#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>

#define RoboticArm_L3 85
#define RoboticArm_L12 200
#define RoboticArm_H 112
#define Gripper_L 77

class Arm : public QObject
{
    Q_OBJECT
public:
    double X, Y, Z;

    double gripperAngle;

    double baseAngle, j1Angle, j2Angle, j3Angle;

    Arm();

    // return type int, 0 -> no problem, -1 -> problem
    int receivePosition();

    int sendPosition();

    void CalculateAngles();

    void CalculateXYZ();

    int setAngle(double gAngle);

    int setXYZ(double x, double y, double z);

    int setAngles(double base, double j1, double j2);

    void print();

    int AngleToSteps(double angle);

    double StepsToAngle(int steps);

signals:
    void Error(int e);

};

#endif // COMMUNICATION_H
