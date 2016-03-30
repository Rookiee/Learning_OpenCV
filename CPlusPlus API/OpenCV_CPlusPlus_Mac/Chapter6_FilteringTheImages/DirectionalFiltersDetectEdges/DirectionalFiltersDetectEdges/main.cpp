//
//  main.cpp
//  DirectionalFiltersDetectEdges
//
//  Created by XieHaoyang on 12/27/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    // Open Image
    Mat imageSrc = imread("/Users/Haoyang/Downloads/Pics/boldt.jpg",0);
    if(imageSrc.empty()) {
        cout << "Error" << endl;
        exit(EXIT_FAILURE);
    }
    Mat sobeX;
    Mat sobeY;
    
    // 在水平和垂直方向测试sobel结果
//    cv::Sobel(imageSrc, sobeX, CV_8U, 1, 0,3,0.4,128);
//    
//    cv::Sobel(imageSrc, sobeY, CV_8U, 0,1,3,0.4,128);
//    namedWindow("SobeX");
//    imshow("SobeX",sobeX);
//    
//    namedWindow("SobeY");
//    imshow("SobeY", sobeY);
    
    
    // COmpute norm of sobel
    Sobel(imageSrc, sobeX, CV_16S, 1, 0);
    Sobel(imageSrc, sobeY, CV_16S, 0, 1);
    Mat sobe;
    // compute the L1 norm
    sobe = abs(sobeX) + abs(sobeY);
    
    // 看看能不能显示sobe
//    namedWindow("sobe");
//    imshow("sobe",sobe);    // 显示不出来，全是灰色
    
    // 显示sobe
    // Find sobe max value
    double sobmin, sobmax;
    minMaxLoc(sobe, &sobmin, &sobmax);
    // Conversion to 8-bit image
    // sobeImage = -alpha*sobe + 255
    Mat sobeImage;
    sobe.convertTo(sobeImage, CV_8U,-255./sobmax,255);
    namedWindow("sobeImage");
    imshow("sobeImage",sobeImage);
    
    //已经获取和显示了 sobeImage，
    // 现在，通过threshold 获取binary map
    Mat thresholdImage;
    for(int threshold = 0; threshold != 256; ++threshold) {
        cv::threshold(sobeImage, thresholdImage, threshold, 255, cv::THRESH_BINARY);
        namedWindow("Threshold");
        imshow("Threshold",thresholdImage);
        cout << threshold << endl;
        waitKey(100);
//        destroyAllWindows();
    }
    
    
    waitKey();
    
    return 0;
}
