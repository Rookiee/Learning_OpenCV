#ifndef MORPHOFEATURES
#define MORPHOFEATURES

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <opencv2/highgui/highgui.hpp>
class MorphoFeatures {

private:

    // threshold to produce  binary map
    int threshold;
    // structing elements used in corner detection
    cv::Mat cross;
    cv::Mat diamond;
    cv::Mat square;
    cv::Mat x;

    void applyThreshold(cv::Mat image){
        // apply threshold on image
        if(threshold > 0){
            cv::threshold(image,image,threshold,255,cv::THRESH_BINARY);
        }

    }

public:
    // 仅仅使用getEdges(), 不需要这个构造函数
    MorphoFeatures():threshold(-1),
        cross(5,5,CV_8U,cv::Scalar(0)),
        diamond(5,5,CV_8U,cv::Scalar(1)),
        square(5,5,CV_8U,cv::Scalar(1)),
        x(5,5,CV_8U,cv::Scalar(0)) {
        // Creating the cross-shaped structing element
        for(int i = 0; i < 5; ++i) {
            cross.at<uchar>(2,i) = 1;
            cross.at<uchar>(i,2) = 1;
        }

        // Creating the diamond-shaped structing element
        diamond.at<uchar>(0,0) = 0;
        diamond.at<uchar>(0,1) = 0;
        diamond.at<uchar>(1,0) = 0;
        diamond.at<uchar>(4,4) = 0;
        diamond.at<uchar>(3,4) = 0;
        diamond.at<uchar>(4,3) = 0;
        diamond.at<uchar>(4,0) = 0;
        diamond.at<uchar>(4,1) = 0;
        diamond.at<uchar>(3,0) = 0;
        diamond.at<uchar>(0,4) = 0;
        diamond.at<uchar>(0,3) = 0;
        diamond.at<uchar>(1,4) = 0;

        // Create X-shaped structing element
        for (int i = 0; i< 5; ++i) {
            x.at<uchar>(i,i) = 1;
            x.at<uchar>(4-i,i) = 1;
        }
    }


    cv::Mat getEdges(const cv::Mat& image) {
        // Get the gradient image
        cv::Mat result;
        cv::morphologyEx(image,result,cv::MORPH_GRADIENT,cv::Mat());
        // Apply threshold to obtain a binary map
        // 输出result 看看是不是灰度图
        cv::namedWindow("Gradient");
        cv::imshow("Gradient",result);
        cv::waitKey();

        applyThreshold(result);
        return result;
    }

    void setThreshold(int threshold_) {
        threshold = threshold_;
    }

    /*********************一下代码用于coner detection***************************/
    cv::Mat getCorner(const cv::Mat &image) {
        cv::Mat result;
        // Dilate with a cross
        cv::dilate(image,result,cross);

        // Erode with a diamond
        cv::erode(result,result,diamond);

        cv::Mat result2;
        // Dilate with a X
        cv::dilate(image,result2,x);
        // Erode with a square
        cv::erode(result2,result2,square);

        // Corners are obtained by differencing the two closed images
        cv::absdiff(result2,result,result);
        applyThreshold(result);
        return result;
    }

    // Visualize the result of the detection
    void drawOnImage(const cv::Mat& binary, cv::Mat& image) {
        cv::Mat_<uchar>::const_iterator it =
                binary.begin<uchar>();
        cv::Mat_<uchar>::const_iterator itend =
                binary.end<uchar>();

        // For each pixel
        for (int i = 0; it != itend; ++it, ++i) {
            if( !*it ){
                cv::circle(image,
                           cv::Point(i%image.step,i/image.step),
                           5,cv::Scalar(255,0,0));
            }
        }
    }
};

#endif // MORPHOFEATURES

