#include "arm.h"

#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <math.h>

#include <QTextStream>

Arm::Arm()
{
    receivePosition();

    this->X = 200;
    this->Y = 200;
    this->Z = 0;

    // Vertically to the screen
    this->gripperAngle = 0;
    //this->gripperAngle = M_PI / 4;

    this->CalculateAngles();
    this->print();

    this->CalculateXYZ();
    this->print();

}

void Arm::print()
{
    QTextStream(stdout) << "Arm Position [ X, Y, Z ] is [ " << this->X << ", " << this->Y << ", " << this->Z << " ]" << endl;
    QTextStream(stdout) << "Gripper Angle: " << this->gripperAngle * (180/M_PI) << endl;
    QTextStream(stdout) << "Base Angle: " << this->baseAngle * (180/M_PI) << ", J1 Angle: " << this->j1Angle * (180/M_PI) << ", J2 Angle: " << this->j2Angle  * (180/M_PI) << ", J3 Angle: " << this->j3Angle * (180/M_PI) << endl << endl;
}

int Arm::receivePosition()
{
    // RECEIVE POSITION

    return 0;
}

int Arm::sendPosition()
{
    // SEND POSITION

    return 0;
}

int Arm::AngleToSteps(double angle)
{
    int steps = angle / (2 * M_PI / 4096);
    return steps;
}

double Arm::StepsToAngle(int steps)
{
    double angle = steps * (2 * M_PI / 4096);
    return angle;
}

void Arm::CalculateAngles()
{
    // Calculate base, j1, j2, j3 angles from [ X, Y, Z ] and gripper angle
    QTextStream(stdout) << "CalculateAngles" << endl << endl;

    // ANGLES
    double alfa_1j3, alfa_12, alfa_23, alfa_j3r, theta_S, alfa_3j3, alfa_2j3, alfa_j3z, alfa_j2;

    // LINE SEGMENTS
    double j3G, rs, j2, j3, j3S;

    // ARMS
    double r2 = RoboticArm_L12, r3 = RoboticArm_L3, g = Gripper_L;

    // COORDINATES
    double J3_w, J3_z;

    double w = sqrt(pow(this->X, 2) + pow(this->Y, 2));

    j3G = sqrt(pow(r3, 2) + pow(g, 2));

    rs = sqrt(pow(w, 2) + pow(this->Z, 2));

    theta_S = acos(w / rs);

    alfa_3j3 = acos(r3 / j3G);

    J3_w = sin(this->gripperAngle - alfa_3j3) * j3G + w;
    J3_z = cos(this->gripperAngle - alfa_3j3) * j3G + this->Z;

    j3 = sqrt(pow(J3_w, 2) + pow(J3_z, 2));
    j3S = j3 / 2;

    j2 = sqrt(pow(r2, 2) - pow(j3S, 2));

    alfa_2j3 = acos(j3S / r2);

    alfa_1j3 = alfa_2j3;

    alfa_j3z = acos(J3_z / j3);

    alfa_j2 = acos(j2 / r2);

    alfa_j3r = acos((pow(j3, 2) + pow(rs, 2) - pow(j3G, 2)) / (2 * j3 * rs));

    alfa_12 = alfa_j2 * 2;

    alfa_23 = alfa_2j3 + alfa_j3z - this->gripperAngle;


    this->baseAngle = M_PI - (atan(this->Y / (double)this->X));
    this->j1Angle = M_PI - (alfa_1j3 + alfa_j3r + theta_S);
    this->j2Angle = alfa_12;
    this->j3Angle = 2 * M_PI - alfa_23;

    if (this->X < 0 && this->Y < 0)
    {
        this->baseAngle += M_PI;
    }
    else if (this->X < 0 && this->Y > 0)
    {
        this->baseAngle -= M_PI;
    }
}

void Arm::CalculateXYZ()
{
    // Calculate [ X, Y, Z ] from base, j1, j2 angles and gripper angle
    QTextStream(stdout) << "CalculateXYZ" << endl << endl;

    // COORDINATES
    double z1, z2, z3;
    double w, w1, w2, w3;

    // ANGLES
    double beta1, beta3;
    double alpha2, alpha3;
    double j0, j1, j2;

    // ARMS
    double r12 = RoboticArm_L12, r3 = RoboticArm_L3, g = Gripper_L;

    // LINE SEGMENTS
    double c;

    j0 = M_PI - this->baseAngle;
    j1 = M_PI - this->j1Angle;
    j2 = this->j2Angle;

    z1 = sin(j1) * r12;
    w1 = cos(j1) * r12;

    beta1 = (M_PI/2) - j1;

    alpha2 = j2 - beta1;

    z2 = -cos(alpha2) * r12;
    w2 = sin(alpha2) * r12;

    c = sqrt(pow(r3, 2) + pow(g, 2));

    beta3 = asin(r3 / c);

    alpha3 = this->gripperAngle + beta3;

    // Sprave je to naopak?
    z3 = -sin(alpha3) * c;
    w3 = cos(alpha3) * c;

    this->Z = z1 + z2 + z3;
    w = w1 + w2 + w3;

    this->Y = sin(j0) * w;
    this->X = cos(j0) * w;

    // nechat ??
    this->X = round(this->X);
    this->Y = round(this->Y);
    this->Z = round(this->Z);

/*
    QTextStream(stdout) << "j0 Angle: " << j0 * (180/M_PI) << ", j1 Angle: " << j1 * (180/M_PI) << ", j2 Angle: " << j2  * (180/M_PI) << endl;
    QTextStream(stdout) << "Beta 1: " << beta1 * (180/M_PI) << ", Beta 3: " << beta3 * (180/M_PI) << endl;
    QTextStream(stdout) << "Alpha 2: " << alpha2 * (180/M_PI) << ", Alpha 3: " << alpha3 * (180/M_PI) << endl;

    QTextStream(stdout) << "w1, z1 : " << w1 << ", " << z1 << endl;

    QTextStream(stdout) << "w2, z2 : " << w2 << ", " << z2 << endl;

    QTextStream(stdout) << "w3, z3 : " << w3 << ", " << z3 << endl << endl;
*/

}

int Arm::setAngle(double gAngle)
{
    // TODO

    // SET ANGLE
    QTextStream(stdout) << "Set angle to: " << gAngle << endl;

    return 0;
}

int Arm::setXYZ(double x, double y, double z)
{
    // SET XYZ
    QTextStream(stdout) << "Set [X, Y, Z] to: [" << x << ", " << y << ", " << z << "] " << endl;

    //delete later
    this->X = x;
    this->Y = y;
    this->Z = z;

    CalculateAngles();

    return sendPosition();
}

int Arm::setAngles(double base, double j1, double j2)
{
    // SET STEPS
    QTextStream(stdout) << "Set base, j1, j2 angles to: " << base << ", " << j1 << ", " << j2 << endl;

    //delete later
    this->baseAngle = base;
    this->j1Angle = j1;
    this->j2Angle = j2;

    CalculateXYZ();

    return sendPosition();
}
