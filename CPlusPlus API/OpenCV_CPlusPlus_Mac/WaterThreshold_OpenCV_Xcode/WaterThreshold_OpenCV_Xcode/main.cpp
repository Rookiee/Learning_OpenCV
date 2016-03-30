//
//  main.cpp
//  WaterThreshold_OpenCV_Xcode
//
//  Created by XieHaoyang on 12/26/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//
#include "WathershedSegmenter.h"
#include <opencv2/highgui/highgui.hpp>


#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    // 读取图片
    Mat binary = imread("/Users/Haoyang/Downloads/Pics/binary.bmp");
    if( binary.empty())
        cout << "你妹" << endl;
    
    // Eliminate noise and smaller objects
    cv::Mat fg;
    cv::erode(binary, fg, cv::Mat(),cv::Point(-1,-1), 6);
//    namedWindow("FG");
//    imshow("FG",fg);
    
    // Identify image pixels without objects
    cv::Mat bg;
    cv::dilate(binary, bg, cv::Mat(),cv::Point(-1,-1),6);
    cv::threshold(bg, bg, 1, 128, cv::THRESH_BINARY_INV);
//    namedWindow("BG");
//    imshow("BG",bg);
    
    // Create markers image
    cv::Mat markers(binary.size(),CV_8U,cv::Scalar(0));
    markers = fg + bg;
    cout << markers.cols << " " << markers.rows << endl;
    cout << binary.cols << " " << binary.rows << endl;
    Mat image = imread("/Users/Haoyang/Downloads/Pics/group.jpg");
    

//    // Create watershed segmentation object
//    WathershedSegmenter * segmenter = new WathershedSegmenter;
//    segmenter->setMarkers(markers);
//    Mat result = segmenter->process(image);
//    namedWindow("Result");
//    imshow("Result",image);
//    waitKey();
    cv::watershed(binary, markers);
 
    
    return 0;
}
