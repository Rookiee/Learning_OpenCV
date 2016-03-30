#ifndef ERODEANDDILATE_H
#define ERODEANDDILATE_H
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
class ErodeandDilate {
private:
    cv::Mat original;
    cv::Mat erode;
    cv::Mat dilate;
    cv::Mat element;
    int div;

    // set and get element
    void setElement() {
        cv::Mat tmp(div,div,CV_8U,cv::Scalar(1));
        element = tmp;

    }

public:
    ErodeandDilate() : div(3) {}

    int getDiv() {
        return div;
    }

    // Set original
    void setOriginal(cv::Mat & image) {
        original = image;
    }

    // Get original
    cv::Mat getOriginal() {
        return original;
    }

    // set div
    void setDiv(int div_) {
        div = div_;
    }



    // get erode
    cv::Mat getErode(){
        setElement();
        cv::erode(original,erode,element);
        std::cout << "In getErode(): " << getDiv() << std::endl;
        return erode;
    }

    // get dilate
    cv::Mat getDilate() {
        setElement();
        cv::dilate(original,dilate,element);
        std::cout << "In getDilate(): " << getDiv() << std::endl;
        return dilate;
    }


};

#endif // ERODEANDDILATE_H

