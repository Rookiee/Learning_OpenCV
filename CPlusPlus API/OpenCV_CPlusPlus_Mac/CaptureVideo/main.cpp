#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;

int main()
{
    cvNamedWindow("camera");
    CvCapture * capture = cvCreateCameraCapture(-1);
//    CvCapture * capture =  FileCapture("/Users/Haoyang/Downloads/long.avi");
    IplImage * frame;

    while(1) {
        frame = cvQueryFrame(capture);
        if(!frame)
            break;
        cvShowImage("camera",frame);
        char c = cvWaitKey(20);
        if(c==27)
            break;

    }

    cvReleaseCapture(&capture);
    cvDestroyWindow("camera");
    return 0;

}

