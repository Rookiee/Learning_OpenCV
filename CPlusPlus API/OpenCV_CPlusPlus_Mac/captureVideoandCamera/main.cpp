#include <QCoreApplication>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cvNamedWindow("avi");
    CvCapture * capture = cvCreateCameraCapture(-1);
    IplImage * frame;
    while(1) {
        frame = cvQueryFrame(capture);
        if(!frame) break;
        cvShowImage("avi",frame);
        char c = cvWaitKey(33);
        if(c==27)
            break;
    }
    return a.exec();
}

