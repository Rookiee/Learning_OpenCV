#ifndef ERODEANDDIALATE
#define ERODEANDDIALATE

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class ErodeAndDialate {
    cv::Mat imageErode;
    cv::Mat imageDilate;
    cv::Mat element;

    int div; // 用来设置 structing element 的大小

public:
    ErodeAndDialate() : div(3) {
        element = getElement(div);
    }

    // 设置element
    cv::Mat getElement(int div) {
        cv::Mat result(div,div,CV_8U,cv::Scalar(1));
        element = result;
        return element;
    }

    // 设置 imageErode 和 imageDilate
    void setImageErode(const cv::Mat& image) {
        imageErode = image;
    }

    void setImageDilate(const cv::Mat& image) {
        imageDilate = image;
    }

    // 获取 Erode 和 Dilate 后的图像
    cv::Mat getErode() {
        cv::erode(imageErode,imageErode,element);
        return imageErode;

    }

    cv::Mat getDilate() {
        cv::dilate(imageDilate,imageDilate,element);
        return imageDilate;
    }



};

#endif // ERODEANDDIALATE

