//
//  LaplacianZC.h
//  Laplacian_High_Pass_Console_Xcode
//
//  Created by XieHaoyang on 12/27/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#ifndef LaplacianZC_h
#define LaplacianZC_h
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

class LaplacianZC {
private:
    // original image
    cv::Mat imageSrc;
    
    // 32-bit float image containing the Laplacian
    cv::Mat laplacian;
    
    // Aperture size of the laplacian kernel
    int aperture;
    
public:
    LaplacianZC() : aperture(3) {}
    
    // set the aperture size of the kernel
    void setAperture(int a) {
        aperture = a;
    }
    /******************** Compute Laplacian *****************/
    // Compute the floating point Laplacian
    cv::Mat computeLaplacian(const cv::Mat& image) {
        // compute Laplacian
        cv::Laplacian(image,laplacian,CV_32F,aperture);
        
        // keep local copy of the image
        // ( used for zero-corssings)
        imageSrc = image.clone();
        return laplacian;
    }
    /*****************visulize image***********************/
    
    // Get the Laplacian result in 8-bit image
    // zero corresponds to gray-level 128
    // if no scale is provided, then the max value will be scalled to intensity 255
    // must call computeLaplacian before calling this
    cv::Mat getLaplacianImage(double scale = -1.0) {
        if(scale < 1) {
            double lapmin, lapmax;
            cv::minMaxLoc(laplacian,&lapmin, &lapmax);
            scale = 127/ std::max(-lapmin,lapmax);
        }
        
        cv::Mat laplaceImage;
        laplacian.convertTo(laplaceImage,CV_8U,scale,128);
        return laplaceImage;
    }
    
     /*****************zero-crossings***********************/
    // Get a binary image of the zero-corssings
    // if the product of the two adjascent pixels is
    // less than the threshold then this zero-corssing
    // will be ignored
    cv::Mat getZeroCrossings(float threshold = 1.0) {
        // Create the iterators
        cv::Mat_<float>::const_iterator it = laplacian.begin<float>() + laplacian.step1();
        cv::Mat_<float>::const_iterator itend = laplacian.end<float>();
        cv::Mat_<float>::const_iterator itup = laplacian.begin<float>();
        
        // Binary image initilize to white
        cv::Mat binary(laplacian.size(), CV_8U, cv::Scalar(255));
        cv::Mat_<uchar>::iterator itout = binary.begin<uchar>() + binary.step1();
        
        // negate the input threshold value
        threshold *= -1.0;
        for(; it != itend; ++it, ++itup, ++itout) {
            // if the product of two adjascent pixel is
            // negative, then there is a sign change
            if( *it * *(it-1) < threshold)
                *itout = 0;     // horizontal zero-crossing
            else if ( *it * *itup < threshold )
                itout  = 0;     // vertical zero-crossing
        }
        return binary;
    }
};

#endif /* LaplacianZC_h */
