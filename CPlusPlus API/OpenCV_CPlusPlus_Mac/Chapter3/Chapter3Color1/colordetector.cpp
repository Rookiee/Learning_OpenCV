#include "colordetector.h"
int ColorDetector::getDistance(const cv::Vec3b &color) const
{
	return abs(color[0] - target[0]) + 
           abs(color[1] - target[1]) +
           abs(color[2] - target[2]);
}

void ColorDetector::setTargetColor(unsigned char red, unsigned char green, unsigned char blue)
{
    target[0] = blue;
    target[1] = green;
    target[2] = red;
}

void ColorDetector::setTargetColor(cv::Vec3b color) 
{
    target = color;
}

void ColorDetector::setColorDistanceThreshold(int distance)
{
    if(distance < 0)
        distance = 0;
    miniDistance = distance;
}

cv::Mat ColorDetector::Process(const cv::Mat &image)
{
    result.create(image.rows, image.cols, CV_8U);

    VecIterator itbeg = image.begin<cv::Vec3b>();
    VecIterator itend = image.end<cv::Vec3b>();
    UcharIterator itout = result.begin<uchar>();

    qDebug() << image.at<cv::Vec3b>(10,10)[0]
    << image.at<cv::Vec3b>(10,10)[1]
    << image.at<cv::Vec3b>(10,10)[2];

   for(; itbeg != itend; ++itbeg, ++itout) {
       if(getDistance(*itbeg) < miniDistance) {
           *itout = 255;
       }
       else
           *itout = 0;
   }

   qDebug() << result.at<cv::Vec3b>(10,10)[0]
   << result.at<cv::Vec3b>(10,10)[1]
   << result.at<cv::Vec3b>(10,10)[2];


   return result;
}



