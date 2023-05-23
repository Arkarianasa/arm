
#include "senddata.h"
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <math.h>
#include <QTextStream>

#define _USE_MATH_DEFINES

SendData::SendData(QObject *parent) :
    QObject(parent)
{
    //time=1500;
    X = 5;
    Z = 15;
    angle = 0;
}

int SendData::Init(char* port,long BAUD){
    this->PrepareSerial(port, BAUD);
    if(CheckRun())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int SendData::PrepareSerial(char *port, long baud){
    struct termios newkey;
    fd = open(port, O_RDWR | O_NOCTTY);
    if (fd == -1)
    {
        return -1;
    }else{
        newkey.c_cflag = baud | CLOCAL | CREAD;
        newkey.c_iflag = IGNPAR;
        newkey.c_oflag = 0;
        newkey.c_lflag = 0;
        tcflush(fd, TCIFLUSH);
        tcsetattr(fd,TCSANOW,&newkey);
        return 0;
    }
}

bool SendData::CheckRun(){
    char lCommad[100], lReceive[100];
    sprintf(lCommad, "#7 P0\r");
    int lCount = write(fd, lCommad, strlen(lCommad));
    QTextStream(stdout)  << " write succeess!" << endl;
    this->ReadFromFD(lReceive, fd);
    QTextStream(stdout) << "Read succeess! "<< lReceive << " : "<< strlen(lReceive) << endl;
    if(strlen(lReceive) > 0)
        return true;
    return false;
}

void SendData::ReadFromFD(char* lRecBuf, int aFD){
    int n = 0;
    char response[100];
    memset(response, 0x00, sizeof response);

    fd_set set;
    struct timeval timeout;
    FD_ZERO(&set);
    FD_SET(fd, &set);

    timeout.tv_sec = 1;
    timeout.tv_usec = 1;
    QTextStream(stdout) << "waiting for input"<< endl;

    int rv = select(fd + 1, &set, NULL, NULL, &timeout);
    //int rv = 1;
    if(rv == -1)
        QTextStream(stdout) << "select"<< endl;
    else if(rv == 0)
        QTextStream(stdout) << "timeout"<< endl;
    else
    {
        n = read( aFD, &response, 100);
    }

    if (n < 0) {
        QTextStream(stdout) << "Error reading: " << strerror(errno) << endl;
    }
    else if (n == 0) {
        QTextStream(stdout) << "Read nothing!" << endl;
    }
    else {
        QTextStream(stdout) << "Response: " << response << "\n\r " << n << endl;
    }

    strcpy(lRecBuf, response);
    strcpy(mInitBuffer, response);
}

char* SendData::GetInitResponse(){
    return mInitBuffer;
}
void SendData::setTime(int time){
    this->time = time;
}

void SendData::setTime(QString time){
    this->time = time.toInt();
}

void SendData::setServo(int s){
   this->servo = s;
}

void SendData::setServo0(){
   this->servo = 0;
}

void SendData::setServo1(){
   this->servo = 1;
}

void SendData::setServo2(){
   this->servo = 2;
}

void SendData::setServo3(){
   this->servo = 3;
}

void SendData::setServo4(){
   this->servo = 4;
}

void SendData::setServo5(){
   this->servo = 5;
}

void SendData::SetZero(){
    memset(buf, 0x00, sizeof buf);
    //time = 1500;
    servo = 1;
    Prepare(83);
    servo = 2;
    Prepare(150);
    servo = 3;
    Prepare(-66);
    servo = 4;
    Prepare(1);
    servo = 0;
    Prepare(71);
    this->Send();
}

void SendData::SendAngle(int val){
    this->Prepare(val);
    //printf("val: %d \n",val);
    this->Send();
}

int SendData::PrepareAngle(int val){
    if(servo == 3){
        //val = -val;
        val += 90;
        return (560+(val*10));
    }else if(servo == 1){
        val += 90;
        return (633+(val*10));
    }else if(servo == 2){
        val += 42;
        return (503+(val*10));
    }else if(servo == 4){
        return 1119+(11.6*val);
    }else if(servo == 0){
        return 500+(10*val);
    }
    return 0;
}

void SendData::Prepare(int val){
    val = this->PrepareAngle(val);
    if(this->servo >=0 && servo < 32){
        if(servo == 1){
            sprintf(buf, "%s #1 P%d #17 P%d",buf, val, val);
        }else{
            sprintf(buf, "%s #%d P%d",buf, servo, val);
        }
    }
}

void SendData::Send(){
    sprintf(buf,"%s T%d \r",buf,time);
    write(fd, buf,strlen(buf));
    QTextStream(stdout) << buf;
    sprintf(buf,"");
}

void SendData::setX(int x){
    X = x;
}
void SendData::setY(int y){
    Y = y;
}

void SendData::setZ(int z){
    Z = z;
}

void SendData::setAngle(int a){
    angle = a;
}

int SendData::moveXYZ(void){
    int e;
    if((e=this->SolveCoordinates(Z,Y,X,angle))==1){
        emit this->Error(e);
    }else{
        emit this->Error(e);
    }
    return e;
}

QPoint SendData::SolveMax(double a){
    QPoint pt;

    double baseX,baseY,shoulderX,shoulderY,elbowX,elbowY,wristX,wristY,tipX,tipY;
    baseX = 3;
    baseY = 1;
    shoulderX = baseX + 0;
    shoulderY = RoboticArm_H + baseY;
    elbowX = shoulderX + RoboticArm_L12*cos(a*(M_PI/180));
    elbowY = shoulderY + RoboticArm_L12*sin(a*(M_PI/180));
    wristX = elbowX + RoboticArm_L12*cos(a*(M_PI/180));
    wristY = elbowY + RoboticArm_L12*sin(a*(M_PI/180));
    tipX = wristX + RoboticArm_L3*cos(angle*(M_PI/180));
    tipY = wristY + RoboticArm_L3*sin(angle*(M_PI/180));

    pt.setX(tipX-1);
    pt.setY(tipY);

    return pt;

}

int SendData::SolveCoordinates(double x, double y, double z, double angle){

    x=x/10;
    z=z/10;
    //QTextStream(stdout) << "draw X:"<<x << " Z:" <<z<< endl;
    if(z < 3){
        return 4;
    }
    double T1, T2, T3;
    double P1, P2;
    double Xb, Q, Zb;
    double rot;

    Xb = (x - RoboticArm_L3 * cos(angle * (M_PI/180)))/(2 * RoboticArm_L12);
    Zb = (z - RoboticArm_H - RoboticArm_L3 * sin(angle * M_PI/180))/(2 * RoboticArm_L12);
    Q = sqrt(1/(pow(Xb,2) + pow(Zb,2)) - 1);

    P1 = atan2(Zb+(Q*Xb),Xb-(Q*Zb)) * 180 / M_PI;
    P2 = atan2(Zb-Q*Xb,Xb+Q*Zb) * 180 / M_PI;

    T1 = P1-90;
    T2 = -(P2-P1);
    T3 = (angle-P2);

    T1 = T1 - round(T1/360)*360;
    T2 = T2 - round(T2/360)*360;
    T3 = T3 - round(T3/360)*360;


    baseX = 3;
    baseY = 1;
    shoulderX = baseX + 0;
    shoulderY = RoboticArm_H + baseY;
    elbowX = shoulderX + RoboticArm_L12*cos(P1*(M_PI/180));
    elbowY = shoulderY + RoboticArm_L12*sin(P1*(M_PI/180));
    wristX = elbowX + RoboticArm_L12*cos(P2*(M_PI/180));
    wristY = elbowY + RoboticArm_L12*sin(P2*(M_PI/180));
    tipX = wristX + RoboticArm_L3*cos(angle*(M_PI/180));
    tipY = wristY + RoboticArm_L3*sin(angle*(M_PI/180));


    rot = atan(y/tipX)*180/M_PI;

    memset(buf, 0x00, sizeof buf);
    ///time = 2000;
    servo = 1;
    Prepare(T1);
    servo = 2;
    Prepare(T2);
    servo = 3;
    Prepare(T3);
   // servo = 0;
    //Prepare(rot+90);

    if(pow(Xb,2)+pow(Zb,2) > 1){
        sprintf(buf,"");
        return 1;
    /*}else if(elbowX > 1 && elbowY <= shoulderY){
        sprintf(buf,"");
        return 2;*/
    }else if(elbowY <= shoulderY){
        sprintf(buf,"");
        return 3;
    }else{
        this->Send();
        return 0;
    }

   // printf("T1 = %2f, T2 = %2f, T3 = %2f", P1, P2, T1);

}

double SendData::SolveXYZ(int aServo0, int aServo1, int aServo2, int aServo3, int aServo4, int aServo5)
{
    double x,y,xx,yy;
    y = x = 0;
/*#define RoboticArm_H    6       //height of base (6)
#define RoboticArm_L12  10    //lengths of humerus/ulna
#define RoboticArm_L3   6       //length of hand
#define RoboticARM_S    80      //servo range -S to S (degrees)
*/
    double u0 = GetAngle(0,aServo0);
    double u1 = GetAngle(1,aServo1);
    double u2 = GetAngle(2,aServo2);
    double u3 = GetAngle(3,aServo3);
    double u4 = GetAngle(4,aServo4);
    x += RoboticArm_H;
    //QTextStream(stdout) << "X:" << x<<" Y:"<< y << endl;
    xx = RoboticArm_L12 * cos((-u1*M_PI)/180);
    yy = RoboticArm_L12 * sin((-u1*M_PI)/180);
    //QTextStream(stdout) << "X:"<< x<<"+" << xx<<" Y:"<< y<<"+"<< yy<<" a:"<<u1 << endl;
    x+=xx;y+=yy;


    xx = RoboticArm_L12 * cos(((u2+-u1)*M_PI)/180);
    yy = RoboticArm_L12 * sin(((u2+-u1)*M_PI)/180);
    //QTextStream(stdout) << "X:" <<x<<"+" << xx<<" Y:"<<y<<"+"<<  yy<<" a:"<<u2 << endl;
    x+=xx;y+=yy;

    xx = RoboticArm_L3 * cos(((-u3+(u2+-u1))*M_PI)/180);
    yy = RoboticArm_L3 * sin(((-u3+(u2+-u1))*M_PI)/180);
    QTextStream(stdout) << "u0:" << u0 << " u1:" << u1 << " u2:" << u2 << " u3:" << u3 << " u4:" << u4  << endl;
    //QTextStream(stdout) << "X:" <<x<<"+" << xx<<" Y:"<< y<<"+"<< yy <<" a:"<<u3<< endl;
    x+=xx;y+=yy;
    //QTextStream(stdout)<<"assign"<<endl;
    //QTextStream(stdout) << "X:" << x<<" Y:"<< y <<" a:"<< u3 << endl<< endl;
    X = x*10;
    Z = y*10;
    Y = u0;
    angle = ((-u1) + u2 + (-u3) - 90)*-1;
    angle2 = u4;
    QTextStream(stdout)<<"FINAL ASSIGMENTS" << "X:"<<X << " Y:" <<Y << " Z:" <<Z<< " A:" <<angle << " A2:" <<angle2 << endl;
    return 0.0;
}

double SendData::GetAngle(int servo, double val){
    double aConst = 10;
    double lRet;
    QTextStream(stdout)<<"servo" << servo << " val:" << val<< endl;
    if(servo == 0){
        lRet= (val-500)/aConst;
    }else if(servo == 1){
        lRet= ((val-633)/aConst)-90;
    }else if(servo == 2){
        lRet= ((val-503)/aConst)-42;
    }else if(servo == 3){
        lRet =((val-560)/aConst)-90;
    }else if(servo == 4){
        lRet =(val-1119)/(aConst+1.6);
    }else
    QTextStream(stdout)<<" Ret:" << lRet << endl;
    return lRet;
}

SendData::~SendData(){
    close(fd);
}

