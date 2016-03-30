#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "watershedsegmenter.h"
#include <QDebug>
using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mat binary = imread("/Users/Haoyang/Downloads/Pics/binary.bmp");
    if(binary.empty())
        qDebug() << "你妹";
    Mat fg;
    erode(binary,fg,cv::Mat(),Point(-1,-1),6);
    Mat bg;
    dilate(binary,bg,cv::Mat(),Point(-1,-1),6);
    threshold(bg,bg,1,128,cv::THRESH_BINARY_INV);
    cv::Mat marker(binary.size(),CV_8U,cv::Scalar(0));
    marker = bg + fg;

    WatershedSegmenter * ws = new WatershedSegmenter;
    ws->setMarkers(marker);
    Mat result = ws->process(binary);

    namedWindow("Result");
    imshow("Result",result);
    return a.exec();
}

