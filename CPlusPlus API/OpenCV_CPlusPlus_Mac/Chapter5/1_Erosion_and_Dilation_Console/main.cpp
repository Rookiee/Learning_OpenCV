#include <QCoreApplication>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <iostream>
#include "erodeanddilate.h"

using namespace std;
typedef vector<cv::Mat>::iterator IterMat;
typedef vector<cv::string>::iterator IterStr;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cv::Mat image = cv::imread("/Users/Haoyang/Downloads/Pics/binary.bmp");
    cv::namedWindow("Original");
    cv::imshow("Original",image);
    if(!image.data)
        cout << "你妹" << endl;

    ErodeandDilate *ed = new ErodeandDilate;
    std::cout << ed->getDiv() << std::endl;
    ed->setDiv(1);
    std::cout << ed->getDiv() << std::endl;

    ed->setOriginal(image);

    cv::namedWindow("Erode");
    cv::imshow("Erode",ed->getErode());

    cv::namedWindow("Dilate");
    cv::imshow("Dilate",ed->getDilate());

    delete ed;


//    cv::namedWindow("7*7");
//    cv::Mat element(7,7,CV_8U,cv::Scalar(1));
//    cv::Mat tmp;
//    cv::erode(image,tmp,element);
//    cv::imshow("7*7",tmp);

    return a.exec();
}

