#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;
int main()
{
    Mat erode;
    Mat dilate;
    Mat element(5,5,CV_8U,Scalar(1));
    Mat imageSrc = imread("/Users/Haoyang/Downloads/Pics/building.jpg",0);
    cv::erode(imageSrc,erode,element);
    namedWindow("Edages");
    imshow("Edages",imageSrc-erode);
    namedWindow("Edages1");
    cv::dilate(imageSrc,dilate,element);
    imshow("Edages1",dilate-imageSrc);
    waitKey();
    return 0;
}

