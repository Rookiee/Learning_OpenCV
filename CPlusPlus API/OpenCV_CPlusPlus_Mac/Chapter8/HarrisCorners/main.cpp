#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mat image = imread("/Users/Haoyang/Downloads/Pics/church01.jpg",0);
    if(image.empty()) {
        std::cout << "你妹" << std::endl;
        return 1;
    }
    namedWindow("Original");
    imshow("Original",image);

    Mat cornerStrength;
    cv::cornerHarris(image,cornerStrength,
                   3,   // neighborhood size
                   3,   // aperture size
                   0.01);   // Harris parameter


    // threshold hte corner strength
    Mat harrisCorners;
    double threshold = 0.0001;
    cv::threshold(cornerStrength,harrisCorners,
              threshold,255,cv::THRESH_BINARY_INV);

    namedWindow("harrisCorners");
    imshow("harrisCorners",cornerStrength);
    return a.exec();
}

