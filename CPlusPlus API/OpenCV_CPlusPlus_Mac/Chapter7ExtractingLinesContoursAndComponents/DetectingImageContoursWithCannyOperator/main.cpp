#include <QCoreApplication>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Open an image with gray-level
    Mat imageSrc = imread("/Users/Haoyang/Downloads/Pics/road.jpg",0);
    if(imageSrc.empty()) {
        cerr << "你妹，出错了" << endl;
        return 1;
    }
    // Show original image
    namedWindow("Original");
    imshow("Original",imageSrc);

    // Define contours
    Mat contours;
    cv::Canny(imageSrc,
              contours,
              125,
              350);
    namedWindow("Contours");
    imshow("Contours",contours);

    // inverted image, invert white and black
    Mat contoursInv;
    cv::threshold(contours,
                  contoursInv,
                  128,
                  255,
                  cv::THRESH_BINARY_INV);
    namedWindow("Inv");
    imshow("Inv",contoursInv);


    return a.exec();
}

