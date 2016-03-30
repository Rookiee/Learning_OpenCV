//
//  WathershedSegmenter.h
//  WaterThreshold_OpenCV_Xcode
//
//  Created by XieHaoyang on 12/26/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#ifndef WathershedSegmenter_h
#define WathershedSegmenter_h

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class WathershedSegmenter {
private:
    cv::Mat markers;
public:
    void setMarkers(const cv::Mat &markerImage){
        // 转换为整数图像
        markerImage.convertTo(markers, CV_32S);
    }
    
    cv::Mat process(const cv::Mat &image){
      
        // Apply watershed
        cv::watershed(image, markers);
        return markers;
    }
};


#endif /* WathershedSegmenter_h */
