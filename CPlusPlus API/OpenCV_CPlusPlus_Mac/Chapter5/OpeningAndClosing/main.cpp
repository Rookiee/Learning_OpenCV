#include <QCoreApplication>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QDebug>
using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mat imageSrc = imread("/Users/Haoyang/Downloads/Pics/binary.bmp");

    if(imageSrc.empty())
        qDebug() << "读文件出错";
    namedWindow("Original");
    imshow("Original",imageSrc);

    Mat element(5,5,CV_8U,Scalar(1));
    Mat open,close;
    morphologyEx(imageSrc,open,MORPH_OPEN,element);
    morphologyEx(imageSrc,close,MORPH_CLOSE,element);
    namedWindow("Open");
    imshow("Open",open);
    namedWindow("Close");
    imshow("Close",close);
//    imwrite("/Users/Haoyang/Downloads/Pics/2.bmp",open);

    Mat result;
    erode(imageSrc,result,element);
    dilate(result,result,element);
    namedWindow("Erode, then dilate");
    imshow("Erode, then dilate",result);
//    imwrite("/Users/Haoyang/Downloads/Pics/1.bmp",result);
    return a.exec();
}

