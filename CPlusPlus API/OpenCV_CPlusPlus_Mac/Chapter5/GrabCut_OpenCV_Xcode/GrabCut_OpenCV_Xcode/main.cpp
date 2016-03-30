//
//  main.cpp
//  GrabCut_OpenCV_Xcode
//
//  Created by XieHaoyang on 12/26/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;
int main(int argc, const char * argv[]) {
    // Open image
    Mat image = imread("/Users/Haoyang/Downloads/Pics/group.jpg");
    if(! image.data) {
        cerr << "你妹" << endl;
        return 1;
    }
    
    /************************************************************/
    
    // define bounding rectangle
    cv::Rect rectangle2(10,100,380,180);
    cv::Mat result;
    cv::Mat foreground(image.size(),CV_8UC3,cv::Scalar(255,255,255));
    cv::Mat bkgModel,fgrModel; // the models (internally used)
    
    // GrabCut segmentation
    cv::grabCut(image,  // input image
                result, // segmentation result
                rectangle2,bkgModel,fgrModel,5,cv::GC_INIT_WITH_RECT);
    
    
    // Get the pixels marked as likely foreground
    //	cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ);
    result= result&1;
    image.copyTo(foreground,result); // bg pixels not copied
    
//    // draw rectangle on original image
//    cv::rectangle(image, rectangle2, cv::Scalar(255,255,255),1);
//    cv::namedWindow("Image 2");
//    cv::imshow("Image 2",image);
    
    // display result
    cv::namedWindow("Foreground objects");
    cv::imshow("Foreground objects",foreground);
    
    cv::waitKey();
    waitKey();
    
    return 0;
}
