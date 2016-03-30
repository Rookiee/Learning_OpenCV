#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H

//opencv
#include <opencv2/core/core.hpp>
//cvtColor()
#include <opencv2/opencv.hpp>


class ColorDetector
{
    typedef cv::Mat_<cv::Vec3b>::iterator VecIterator;
    typedef cv::Mat_<uchar>::iterator UIterator;
private:
    //minimum acceptable distance
    int minDist;

    //target color
    cv::Vec3b target;

    //image containing result binary map
    cv::Mat result;

    // image containing color converted image
    cv::Mat converted;

    // inline private member function
    // Computes the distance from target color.
    int getDistance(const cv::Vec3b& color) const{
//        return static_cast<int>(cv::norm<int,3>(cv::Vec3b(color[0]-target[0],
//                                    color[1]-target[1],color[2]-target[2])));

        return abs(color[0] - target[0]) +
               abs(color[1] - target[1]) +
               abs(color[2] - target[2]);

    }
public:
    //constructor
    ColorDetector() : minDist(100) {
        target[0] = target[1] = target[2] = 0;
    }

    //set minimum acceptable distance
    void setColorDistanceThreshold(int distance) {
       minDist = distance;
    }

    //get minimum acceptable distance
    int getColorDistanceThreshold() const {
        return minDist;
    }

    //set the color to be detected
    void setTargetColor(uchar red, uchar green, uchar blue) {
        //Temporary 1-pixel image
        cv::Mat tmp(1,1,CV_8U);
        tmp.at<cv::Vec3b>(0,0)[0] = blue;
        tmp.at<cv::Vec3b>(0,0)[1] = green;
        tmp.at<cv::Vec3b>(0,0)[2] = red;

        //coverting the target to Lab color space
        cv::cvtColor(tmp,tmp,CV_BGR2Lab);

        target = tmp.at<cv::Vec3b>(0,0);
    }

    //overload setTargetColor method
    void setTargetColor(const cv::Vec3b color) {  // there is no const accordance to answer
        //Temporary 1-pixel image
        cv::Mat tmp(1,1,CV_8U);
        tmp.at<cv::Vec3b>(0,0) = color;

        //converting the target to Lab color space
        cv::cvtColor(tmp,tmp,CV_BGR2Lab);

        target = tmp.at<cv::Vec3b>(0,0);
    }

    // Gets the color to be detected
    cv::Vec3b getTargetColor() const {
        return target;
    }

    // Processes the image. Returns a 1-channel binary image.
    cv::Mat process(const cv::Mat& image);

};

#endif // COLORDETECTOR_H
