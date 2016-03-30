//
//  main.cpp
//  Low_Pass_Filters_Console_Xcode
//
//  Created by XieHaoyang on 12/27/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    // 载入图像
    Mat imageGray = imread("/Users/Haoyang/Downloads/Pics/boldt.jpg");
    if (imageGray.empty()) {
        cout << "你妹，出错了" << endl;
        exit(EXIT_FAILURE);
    }
    
    /**********************************************************************/
    // cv::blur
    // 新建图像，用来保存cv::blur之后的图像
//    Mat result;
//    cv::blur(imageGray, result, cv::Size(5,5));
//    namedWindow("After Blur");
//    imshow("After Blur",result);
    
    /**********************************************************************/
    // Gaussian Function, 加权计算
    Mat result1;
    // 第三和第四个参数中的一个可以用0代替，那么，openCV将根据其中一个参数，计算出另一个参数
    // 的最优值。
    cv::GaussianBlur(imageGray, result1, Size(5,5), 1.5);
    
//    namedWindow("GaussianBlur");
//    imshow("GaussianBlur", result1);
    
    // 计算高斯核
    Mat gauss = cv::getGaussianKernel(9, 1.5);
    // filter2D function
    Mat after;
    cv::filter2D(imageGray, after, 3, gauss);
    namedWindow("After");
    imshow("After",after);
    
    // half an image    and double an image
    Mat reducedImage;
    Mat doubleImage;
    cv::pyrDown(imageGray, reducedImage);
    cv::pyrUp(imageGray, doubleImage);
//    namedWindow("Half");
//    namedWindow("Double");
//    imshow("Half",reducedImage);
//    imshow("Double", doubleImage);
    
    
    
    
    // using resize function
    Mat resizeImage;
    resize(imageGray, resizeImage, Size(imageGray.cols/3,imageGray.rows/3));
//    namedWindow("Resize");
//    imshow("Resize",resizeImage);
    waitKey();
    return 0;
}
