#include "camera.h"
#include <QThread>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QTextStream>

int iLastX = -1;
 int iLastY = -1;



 int iLowH = 0;
 int iHighH = 179;

  int iLowS = 0;
 int iHighS = 255;

  int iLowV = 0;
 int iHighV = 255;

 int p1 = 100;
int p2 = 100;
 int brg = 0;
 cv::Rect *region;

 cv::Mat imgLines;

Camera::Camera(QWidget *parent)  : QThread(parent)
{
    scene = new MyGraphicsView();
    capture1 = new cv::VideoCapture(2);
    //capture1->set(CV_CAP_PROP_FRAME_WIDTH, 320);
    //capture1->set(CV_CAP_PROP_FRAME_HEIGHT, 240);
    capture1->read(frame);
    moving = false;
}

void Camera::Play(){
    imgLines = cv::Mat::zeros( frame.size(), CV_8UC3 );  //black image
    capture1->read(frame);
    timer = new QTimer(this);
    num_count=0;

  /* cv::namedWindow("Canny", 1);
    cv::createTrackbar( "TrackbarName", "Canny", &p1, 255);

    cv::createTrackbar( "TrackbarName1", "Canny", &p2, 255 );*/

    connect(timer, SIGNAL(timeout()), this, SLOT(dice()));
    timer->start(300);
}

void Camera::Stop(){
    timer->stop();
    capture1->release();
}

void Camera::Show(){
    /* OpenCV */
    cv::Mat imgHSV;
    cv::Mat imgThresholded;
    std::vector<cv::Mat> channels(3);
    if(capture1->read(frame))
    {
        frame = frame(cv::Rect(0,130,640,170));
        cv::split(frame,channels);
        //frame = frame + cv::Scalar(-50, -50, -50); //increase the brightness by 75 units
        //cv::cvtColor(frame, imgHSV, cv::COLOR_BGR2HSV);

         //cv::inRange(channels[2], cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
       //cv::inRange(imgHSV, cv::Scalar(170, 5, 24), cv::Scalar(179, 255, 255), imgThresholded);
       cv::inRange(channels[2], cv::Scalar(0, 0, 0), cv::Scalar(250, 255, 255), imgThresholded);

    /*
        //morphological opening (remove small objects from the foreground)
        cv::erode(imgThresholded, imgThresholded, getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(1, 1)) );
        cv::dilate( imgThresholded, imgThresholded, getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(1, 1)) );

         //morphological closing (fill small holes in the foreground)
        cv::dilate( imgThresholded, imgThresholded, getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(1, 1)) );
        cv::erode(imgThresholded, imgThresholded, getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(1, 1)) );
    */
       imgThresholded = cv::Mat::ones(imgThresholded.size(), imgThresholded.type()) * 255 - imgThresholded;
        cv::Moments oMoments = cv::moments(imgThresholded);

        double dM01 = oMoments.m01;
         double dM10 = oMoments.m10;
         double dArea = oMoments.m00;
         if (dArea > 10000)
           {
            //calculate the position of the ball
            int posX = dM10 / dArea;
            int posY = dM01 / dArea;

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
            {
             //cv::line(imgLines, cv::Point(posX, posY), cv::Point(iLastX, iLastY), cv::Scalar(0,0,255), 1);



              int size = 100;
              double test;
             if(((posX-size/2) > 0) && ((posY-size/2) > 0) && ((posX-size/2+size) < frame.cols) && ((posY-size/2+size) < frame.rows))
             {
                 cv::Mat roi;
                 cv::Mat circle = cv::Mat::zeros( frame.size(), CV_8UC3 );
                 roi = frame(cv::Rect(posX-size/2, posY-size/2, size, size));
                 cv::cvtColor(roi, imgHSV, cv::COLOR_BGR2HSV);
                 cv::inRange(imgHSV, cv::Scalar(19, 0, 220), cv::Scalar(255, 255, 255), imgThresholded); //Threshold the image

                 //thresh = cv::threshold(gray,127,255,1);

                 //cv::circle(circle,cv::Point(10,10),5,CV_RGB(0,0,160));
                //test = cv::matchShapes(imgThresholded, circle, CV_CONTOURS_MATCH_I1,0);

                 cv::Canny(roi, canny, 338, 543);
                 cv::waitKey(1);

                 //test += 1;
                 int num = 0;
                 imgLines = cv::Mat::zeros( canny.size(), CV_8UC3 );
                 for(int y=0;y<canny.size().height;y++)
                 {
                     uchar *row = canny.ptr(y);
                     for(int x=0;x<canny.size().width;x++)
                     {
                         if(row[x] <= 128)
                         {
                             int area = cv::floodFill(canny, cv::Point(x,y), CV_RGB(0,0,160));

                             cv::line(imgLines, cv::Point(x, y), cv::Point(x+1, y+1), cv::Scalar(0,0,255), 1);
                             cv::imshow( "Display Image", imgLines );
                             if(area>5 && area < 100)
                             {
                                 num++;
                             }
                             area++;
                         }
                     }
                 }
                 if(num > 0){
                     diceMat=canny;
                     emit this->dice_find(num);
                 }
                 cv::waitKey(1);
                // cv::cvtColor(roi, imgHSV, cv::COLOR_BGR2HSV);
               //cv::inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

             }

          }
             iLastX = posX;
            iLastY = posY;
        }
        //cv::imshow( "Display Image", frame );
        cv::waitKey(1);
    }
    //capture1->read(frame);
}

void Camera::dice(){
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec3f> circles;
    std::vector<cv::Vec4i> hierarchy;
    //std::vector<cv::Mat> centers(10);
    cv::Mat  bw;
    if(capture1->read(frame))
    {
        //cv::imshow( "Canny", frame );
        frame = frame(cv::Rect(70,40,640-80,480-100));     //crop image
        scene->showImage(frame);
        bw = cv::Mat::zeros( frame.size(), CV_8UC3 );
        //frame = frame(cv::Rect(0,130,640,170));     //crop image
        //frame = frame(cv::Rect(280,0,290,210));

        //cv::cvtColor(frame, frame, CV_BGR2GRAY);    //greyscale image
        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

        frame.convertTo(frame,-1,3,00);
        int size = 3;
        cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(2* size + 1, 2* size + 1), cv::Point(size,size));    //clear image
        cv::blur(frame,frame,cv::Size(size, size));
        cv::dilate(frame,frame,element);
        cv::erode(frame,frame,element);
        //cv::inRange(frame, cv::Scalar(140, 140, 140), cv::Scalar(255, 255, 255), frame);
        //frame = frame + cv::Scalar(-120, -120, -120);
        //cv::threshold(frame,bw,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
        cv::threshold(frame,bw,0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);
        cv::Canny(bw, bw, 1, 4);    //detect edge
        //cv::HoughCircles(bw,circles,CV_HOUGH_GRADIENT,1,1,10,15,5,10);

        //cv::findContours(bw.clone(),contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);    //find contours
        cv::findContours(bw.clone(),contours,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_NONE);

        int num = 0;
        for ( int i = 0; i < int(contours.size()); i++ )
            if(contours[ i ].size() > 70)
                num++;

        if(moving==false){
            if(num >= 0 && num <= 6 && num_count > DICE_THR){
                emit this->dice_find(num);
                num_count=0;
            }
            if(num >= 0 && num <= 6 && num_b == num){
                num_count++;
            }else{
                num_count=0;
            }
            num_b = num;
            //QTextStream(stdout) << "Not moving, num=" << num << ", num_count=" << num_count << ", num_b=" << num_b << "\n";
        }
    }
    cv::waitKey(1);
}

void Camera::setMoving(bool m){
    moving = m;
}

MyGraphicsView* Camera::getScene(){
    return scene;
}

cv::Mat Camera::getDice(){
    return diceMat;
}


