#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QDebug>

class ColorDetector
{
    typedef cv::Mat_<cv::Vec3b>::const_iterator VecIterator;
    typedef cv::Mat_<uchar>::iterator UcharIterator;
private:
    // minimum acceptable distance
    int miniDistance;
    
    // target color
    cv::Vec3b target;
    //image containing resulting binary map
    cv::Mat result;
    
public:
    ColorDetector() : miniDistance(100) {
        target[0] = target[1] = target[2] = 0;
    }
    int getDistance(const cv::Vec3b& color) const;
    void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);
    void setTargetColor(cv::Vec3b color);
    cv::Vec3b getTargetColor() const { return target; }
    
    void setColorDistanceThreshold(int distance);
    int getColorDistanceThreshold() const { return miniDistance; }
    
    cv::Mat Process(const cv::Mat& image);
    
};

#endif // COLORDETECTOR_H
