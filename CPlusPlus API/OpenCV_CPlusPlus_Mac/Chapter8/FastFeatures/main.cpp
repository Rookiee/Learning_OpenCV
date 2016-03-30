#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mat image = imread("/Users/Haoyang/Downloads/Pics/church01.jpg");
    if(image.empty()) {
        std::cout << "你妹" << std::endl;
        return 1;
    }

    std::vector<cv::KeyPoint> keypoints;
    cv::FastFeatureDetector fast(40);

    fast.detect(image,keypoints);

    cv::drawKeypoints(image,keypoints,image,Scalar(0,255,0),
                      cv::DrawMatchesFlags::DRAW_OVER_OUTIMG);

    namedWindow("Result");
    imshow("Result",image);


    return a.exec();
}

