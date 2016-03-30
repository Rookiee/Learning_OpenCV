#include "colordetector.h"



cv::Mat ColorDetector::process(const cv::Mat &image)
{
    result.create(image.rows,image.cols,CV_8U);

    converted.create(image.rows, image.cols,image.type());
    cv::cvtColor(image,converted,CV_BGR2Lab);
    VecIterator it = converted.begin<cv::Vec3b>();
    VecIterator itend = converted.end<cv::Vec3b>();
    UIterator itout = result.begin<uchar>();

    for(; it != itend; ++it, ++itout) {
        if(getDistance(*it) < minDist)
            (*itout) = 255;
        else
            (*itout) = 0;
    }
    return result;
}
