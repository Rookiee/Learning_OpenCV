#include "salt.h"


cv::Mat& salt(cv::Mat &image, int n) {
    int l = rand() % image.cols;
    int r = rand() % image.rows;

    for (int k = 0; k<n; k++) {
        if(image.channels() == 1) {
            image.at<uchar>(r,l) = 255;
        }
        else if (image.channels() == 3) {
            image.at<cv::Vec3b>(r,l)[0] = 255;
            image.at<cv::Vec3b>(r,l)[1] = 255;
            image.at<cv::Vec3b>(r,l)[2] = 255;
        }
    }
    return image;

}


