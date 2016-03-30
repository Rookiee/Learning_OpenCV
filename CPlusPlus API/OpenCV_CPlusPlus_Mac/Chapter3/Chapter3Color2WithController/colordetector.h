#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class ColorDetector
{
    typedef cv::Mat_<cv::Vec3b>::const_iterator VecIterator;
    /* can not use const_iterator because we need to change the value throught *itout */
//    typedef cv::Mat_<uchar>::const_iterator UIterator;
    typedef cv::Mat_<uchar>::iterator UIterator;
private:
    int minDistance_;
    cv::Vec3b target_;
    cv::Mat result_;

private:
    int getDistance(const cv::Vec3b& color) const;
public:
    ColorDetector();
    void setColorDistanceThreshold(int minDistance);
    int getColorDistanceThreshold() const ;

    void setTargetColor(uchar red, uchar green, uchar blue);
    void setTargetColor(cv::Vec3b color);
    cv::Vec3b getTargetColor() const;

    cv::Mat &process(const cv::Mat &image);

};

#endif // COLORDETECTOR_H
