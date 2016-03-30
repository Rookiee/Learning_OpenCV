#include <QCoreApplication>
#include <opencv2/highgui/highgui.hpp>
#include "harrisdetector.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::Mat image = cv::imread("/Users/Haoyang/Downloads/Pics/church01.jpg",0);
    // Create Harris detector instance
    HarrisDetector harris;
    // Compute Harris values
    harris.detect(image);
    // Detect Harris corners
    std::vector<cv::Point> pts;
    harris.getCorners(pts,0.01);
    // Draw Harris corners
    harris.drawOnImage(image,pts);

    cv::namedWindow("Result");
    imshow("Result",image);
    return a.exec();
}

