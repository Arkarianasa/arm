#ifndef SENDDATA_H
#define SENDDATA_H

#include <QObject>
#include <termios.h>
#include <QPoint>

#define RoboticArm_H    6       //height of base (6)
#define RoboticArm_L12  10    //lengths of humerus/ulna
#define RoboticArm_L3   6       //length of hand
#define RoboticARM_S    80      //servo range -S to S (degrees)

class SendData : public QObject
{
    Q_OBJECT
public:
    explicit SendData(QObject *parent = 0);
    ~SendData();
    int Init(char* port,long BAUD);
    char* GetInitResponse();
    void setServo(int s);
    void setTime(int time);
    void SetZero();
    void Prepare(int val);
    void Send();
    int PrepareAngle(int val);
    int SolveCoordinates(double x, double y, double z, double angle);
    double SolveXYZ(int aServo0, int aServo1, int aServo2, int aServo3, int aServo4, int aServo5);
    QPoint SolveMax(double a);
    double X, Y, Z, angle, angle2;

    double baseX, baseY, shoulderX, shoulderY, elbowX, elbowY, wristX, wristY, tipX, tipY;

signals:
    void Error(int e);


public slots:
    void SendAngle(int val);
    void setServo1();
    void setServo2();
    void setServo3();
    void setServo4();
    void setServo5();
    void setServo0();
    void setTime(QString time);
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    void setAngle(int a);
    int moveXYZ(void);

private:
    int fd, servo;
    int time;
    char buf[100];
    char mInitBuffer[1024];

private slots:
    int PrepareSerial(char* port, long baud);
    bool CheckRun();
    double GetAngle(int a, double val);
    void ReadFromFD(char *lRecBuf, int aFD);

};

#endif // SENDDATA_H
