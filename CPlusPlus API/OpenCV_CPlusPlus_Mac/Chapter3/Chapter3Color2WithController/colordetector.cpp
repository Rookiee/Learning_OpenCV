#include "colordetector.h"


ColorDetector::ColorDetector()
{
    minDistance_ = 100;
    target_[0] = target_[1] = target_[2] = 0;
}

int ColorDetector::getDistance(const cv::Vec3b& color) const
{
    return abs(color[0] - target_[0]) +
           abs(color[1] - target_[1]) +
           abs(color[2] - target_[2]);
}

void ColorDetector::setColorDistanceThreshold(int minDistance) {
    if (minDistance < 0)
        minDistance = 0;
    minDistance_ = minDistance;
}

int ColorDetector::getColorDistanceThreshold() const
{
    return minDistance_;
}

void ColorDetector::setTargetColor(uchar red, uchar green, uchar blue)
{
    target_[0] = blue;
    target_[1] = green;
    target_[2] = red;
}

void ColorDetector::setTargetColor(cv::Vec3b color)
{
    target_ = color;
}

cv::Vec3b ColorDetector::getTargetColor() const
{
    return target_;
}

cv::Mat& ColorDetector::process(const cv::Mat& image)
{
    result_.create(image.rows, image.rows,CV_8U);

    VecIterator it = image.begin<cv::Vec3b>();
    VecIterator itend = image.end<cv::Vec3b>();
    UIterator itout = result_.begin<uchar>();

    for(; it != itend; ++it, ++itout) {
        if(this->getDistance(*it) < minDistance_)
            (*itout) = 255;
        else
            (*itout) = 0;
    }
    return result_;

}


