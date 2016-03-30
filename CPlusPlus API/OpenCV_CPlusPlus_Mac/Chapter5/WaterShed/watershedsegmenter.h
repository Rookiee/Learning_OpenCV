#ifndef WATERSHEDSEGMENTER_H
#define WATERSHEDSEGMENTER_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class WatershedSegmenter {
private:
    cv::Mat markers;
public:
    void setMarkers(const cv::Mat& markerImage) {
        // Convert to image of ints
        markerImage.convertTo(markers,CV_32S);
    }

    cv::Mat process(const cv::Mat& image) {
        // Apply watershed
        cv::watershed(image,markers);
        return markers;
    }

};

#endif // WATERSHEDSEGMENTER_H

