#include "colordetectorcontroller.h"

ColorDetectorController::ColorDetectorController()
{
    controller_ = new ColorDetector;
}

void ColorDetectorController::setColorDistanceThreshold(int distance)
{
    controller_->setColorDistanceThreshold(distance);
}

int ColorDetectorController::getColorDistanceThreshold() const
{
    return this->getColorDistanceThreshold();
}

void ColorDetectorController::setTargetColor(uchar red, uchar green, uchar blue)
{
    this->setTargetColor(red,green,blue);
}

void ColorDetectorController::getTargetColor(uchar &red, uchar &green, uchar &blue) const
{
    cv::Vec3b color = controller_->getTargetColor();

    red = color[2];
    green = color[1];
    blue = color[0];
}

bool ColorDetectorController::setInputImage(std::__1::string fileName)
{
    image = cv::imread(fileName);
    if(!image.data) {
        return false;
    }
    else
        return true;
}

const cv::Mat &ColorDetectorController::getInputImage() const
{
    return image;
}

cv::Mat ColorDetectorController::process()
{
    return this->controller_->process(image);
}

const cv::Mat ColorDetectorController::getLastResult() const
{
    return result;
}

