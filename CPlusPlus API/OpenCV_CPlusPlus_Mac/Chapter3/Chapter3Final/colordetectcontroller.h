#ifndef COLORDETECTCONTROLLER_H
#define COLORDETECTCONTROLLER_H

#include <colordetector.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

class ColorDetectController
{
private:
    //This is important!!!
    static ColorDetectController * singleton;

    ColorDetector * cdetect;
    cv::Mat image;
    cv::Mat result;

    //constructor should be private
    //avoid other application create a new object
    //in this case, all of the instance must be created by singleton
    ColorDetectController() {
        //setting up the application
        cdetect = new ColorDetector;
    }

public:


    //set the colordistance threshold
    void setColorDistanceThreshold(int distance) {
        cdetect->setColorDistanceThreshold(distance);
    }

    //get the color distance threshold
    int getColorDistanceThreshold() const {
        return cdetect->getColorDistanceThreshold();
    }

    //set the color to be detected
    void setTargetColor(uchar red, uchar green, uchar blue) {
        cdetect->setTargetColor(red,green,blue);
    }

    //get target color
    void getTargetColor(uchar& red, uchar& green, uchar& blue) {
        cv::Vec3b color = cdetect->getTargetColor();
        red = color[2];
        green = color[1];
        blue = color[0];
    }

    //set the input image
    bool setInputImage(std::string fileName) { // need include <iostream>
        image = cv::imread(fileName);
        if( !image.data)
            return false;
        else
            return true;
    }

    //return the current image
    const cv::Mat getInputImage() const {
        return image;
    }

    //perform image processing
    void process() {
        result = cdetect->process(image);
    }

    //return the image after processing
    const cv::Mat getLastResult() const {
        return result;
    }

    //Deletes all processors objects created by the controller
    ~ColorDetectController() {
        delete cdetect;
    }


    //Singleton static members
    static ColorDetectController * getInstance() {
        if(singleton == 0)
            singleton = new ColorDetectController;
        return singleton;
    }

    //Releases the singleton instance of this controller
    static void destroy() {
        if(singleton != 0) {
            delete singleton;
            singleton = 0;
        }
    }
};

#endif // COLORDETECTCONTROLLER_H
