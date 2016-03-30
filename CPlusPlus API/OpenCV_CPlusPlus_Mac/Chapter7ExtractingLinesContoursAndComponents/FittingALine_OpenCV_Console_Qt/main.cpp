#include <QCoreApplication>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
#define PI 3.1415926
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mat imageSrc = imread("/Users/Haoyang/Downloads/Pics/road.jpg",0);
    if(imageSrc.empty()) {
        cout << "你妹" << endl;
        return 1;
    }

    // Get contours using Canny
    Mat contours;
    cv::Canny(imageSrc,contours,125,350);
    namedWindow("Test");
    imshow("Test",contours);

    int n = 0;  // select line 0;
    // black image
    vector<cv::Vec4i> lines;
    cv::HoughLinesP(contours,lines,1,PI/180,80,100,20);

    Mat oneline(contours.size(),CV_8U,cv::Scalar(0));
    // white line
    cv::line(oneline,
             cv::Point(lines[n][0],lines[n][1]),
            cv::Point(lines[n][2],lines[n][3]),
            cv::Scalar(255),
            10);
    cv::bitwise_and(contours,oneline,oneline);

    namedWindow("Line");
    imshow("Line",oneline);

    /************************************************/
    std::vector<cv::Point> points;
    // Iterate over the pixels to obtain all point position
    for (int y = 0; y < oneline.rows; ++y) {
        // row y
        uchar *rowPtr = oneline.ptr<uchar>(y);
        for (int x = 0; x < oneline.cols; ++x) {
            // column x
            // if on a contour
            if(rowPtr[x]) {
                points.push_back(cv::Point(x,y));
            }
        }
    }

    Vec4f line1;
    fitLine(Mat(points),line1,
            CV_DIST_L2,
            0,
            0.01,0.01);

    int x0 = line1[2];
    int y0 = line1[3];

    int x1 = x0 - 200*line1[0];
    int y1 = y0 - 200*line1[1];
//    imageSrc = imread("/Users/Haoyang/Downlaods/Pics/road.jpg",0);
    cv::line(imageSrc,Point(x0,y0),Point(x1,y1),Scalar(255),3);

    namedWindow("Result");
    imshow("Result",imageSrc);


    return a.exec();
}

