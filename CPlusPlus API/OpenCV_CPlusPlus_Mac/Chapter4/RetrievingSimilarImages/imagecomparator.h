#ifndef IMAGECOMPARATOR
#define IMAGECOMPARATOR

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
// 要是用 ColorHistogram 中的ColorReduce 函数
#include "colorhistogram.h"
class ImageComparator {
private:
    cv::Mat reference;  // query image
    cv::Mat input;
    cv::MatND refH;
    cv::MatND inputH;

    ColorHistogram hist;
    int div;

public:
    ImageComparator() : div(32) {

    }

    // 对 div 的操作，包括设置和读取
    void setColorReduceFactorDiv(int div_) {
        div = div_;
    }
    int getColorReduceFactorDiv() {
        return div;
    }

    // 对 query image 的操作, 设置reference 和 refH
    void setReferenceImage(const cv::Mat& image) {
        reference = hist.colorReduce(image,div);
        refH = hist.getColorHistogram(reference);
    }

    /* a compare method compares the reference image with a given input image
     * this method return a score / number indicating how the images are.
     * */
    double compare(const cv::Mat& image) {
        input = hist.colorReduce(image);
        inputH = hist.getColorHistogram(input);
        return cv::compareHist(inputH,refH,CV_COMP_INTERSECT);
//        return cv::compareHist(inputH,refH,CV_COMP_CHISQR);
//        return cv::compareHist(inputH,refH,CV_COMP_CORREL);
    }

};

#endif // IMAGECOMPARATOR

