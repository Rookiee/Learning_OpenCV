#include <QCoreApplication>
#include "morphofeatures.h"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::Mat imageSrc = imread("/Users/Haoyang/Downloads/Pics/building.jpg",0);
    if(!imageSrc.data) {
        std::cout << "Error" << std::endl;
        return false;
    }
    MorphoFeatures *mf = new MorphoFeatures;
    mf->setThreshold(40);
    // Get the edges

//    cv::Mat edges;
//    edges = mf->getEdges(imageSrc);
//    namedWindow("Edges");
//    imshow("Edges",edges);


    // Get the corners
    cv::Mat corners;
    corners = mf->getCorner(imageSrc);
    mf->drawOnImage(corners,imageSrc);
    cv::namedWindow("Corner");
    imshow("Corner",imageSrc);
    return a.exec();
}

