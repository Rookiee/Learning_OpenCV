#include <QCoreApplication>
#include <QDebug>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
//#include <opencv2/opencv.hpp>

#include <vector>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mat image1 = imread("/Users/Haoyang/Downloads/boldt.jpg");
    if(!image1.data) {
        qDebug() << "Error";
        exit(0);
    }


    Mat image2 = imread("/Users/Haoyang/Downloads/rain.jpg");
    if(!image2.data) {
        qDebug() << "Error";
        exit(1);

    }
    qDebug() << "Every image has been read!";
    if(image1.rows != image2.rows || image1.cols != image2.cols) {
        qDebug() << "These two image can not be added!";
    }

    Mat result = 0.7*image1 + 0.9*image2 ;

//    namedWindow("Result with operator");
//    imshow("Result with operator",result);
/**********************************************************
 *  split
 *
//    cv::Mat result;
//    std::vector<cv::Mat> planes;
//    split(image1,planes);
//    planes[0] += image2;
//    merge(planes,result);

//    namedWindow("Result on blue channel");
//    imshow("Result on blue channel",result);

***********************************************************/

    cv::Mat logo = imread("/Users/Haoyang/Downloads/logo.bmp");

    //load the mask(must be gray-level)
    Mat mask = imread("/Users/Haoyang/Downloads/logo.bmp",0);

    //define image ROI
    cv::Mat imageROI;
    imageROI = image1(cv::Rect(20,20,logo.cols,logo.rows));



    //copy to ROI with mask
    logo.copyTo(imageROI,mask);

    //add logo to the result image
    imageROI = imageROI + 0.3*logo;

    namedWindow("ROI");
    imshow("ROI",image1);
    return a.exec();
}

