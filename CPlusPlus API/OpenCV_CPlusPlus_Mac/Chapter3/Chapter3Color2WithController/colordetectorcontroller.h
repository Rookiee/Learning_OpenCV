#ifndef COLORDETECTORCONTROLLER_H
#define COLORDETECTORCONTROLLER_H
#include "colordetector.h"
#include <QString>
#include <iostream>
class ColorDetectorController
{
private:
    ColorDetector * controller_;
    cv::Mat image;
    cv::Mat result;
public:
    ColorDetectorController();
    void setColorDistanceThreshold(int distance);
    int getColorDistanceThreshold() const;
    void setTargetColor(uchar red, uchar green, uchar blue);
    void getTargetColor(uchar& red, uchar& green, uchar& blue)const ;

    bool setInputImage(std::string fileName);
    // the next method according to text is:
    //  const cv::Mat getInputImage() const;
    const cv::Mat& getInputImage() const;

    cv::Mat process();
    const cv::Mat getLastResult() const;

    ~ColorDetectorController() {
        delete controller_;
    }

};

#endif // COLORDETECTORCONTROLLER_H
