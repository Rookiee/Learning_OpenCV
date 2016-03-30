//
//  main.cpp
//  Laplacian_High_Pass_Console_Xcode
//
//  Created by XieHaoyang on 12/27/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include <iostream>
#include "LaplacianZC.h"

int main(int argc, const char * argv[]) {
    cv::Mat image = cv::imread("/Users/Haoyang/Downloads/Pics/boldt.jpg");
    
    LaplacianZC *lap = new LaplacianZC;
    lap->setAperture(7);
    cv::Mat flap = lap->computeLaplacian(image);
    cv::Mat laplace = lap->getLaplacianImage();
//    cv::namedWindow("Result");
//    cv::imshow("Result",laplace);
    
    cv::Mat zero;
    zero = lap->getZeroCrossings();
    cv::namedWindow("Zero");
    cv::imshow("Zero", zero);
    cv::waitKey();
    return 0;
}
