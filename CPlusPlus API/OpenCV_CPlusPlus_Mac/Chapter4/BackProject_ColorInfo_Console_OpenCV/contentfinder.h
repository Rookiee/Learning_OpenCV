#ifndef CONTENTFINDER
#define CONTENTFINDER

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>


class ContentFinder {
private:
    float hranges[2];
    const float* ranges[3];
    int channels[3];
    float threshold;
    cv::MatND histogram;

public:
    ContentFinder() : threshold(-1.0f) {
        // all channels have the same range
        hranges[0] = 0;
        hranges[1] = 255.0;
        ranges[0] = hranges;
        ranges[1] = hranges;
        ranges[2] = hranges;

        channels[0] = 0;
        channels[1] = 1;
        channels[2] = 2;
    }

    /********************************************************/
    // 设置threshold 阀值
    void setThreshold( float threshold_) {
        threshold  = threshold_;
    }
    /********************************************************/

    /********************************************************/
    // 获取 threshold 阀值
    float getThreshold () const {
        return threshold;
    }
    /********************************************************/

    /********************************************************/
    // 输入的直方图必须 normalized
    // 设置 直方图 histogram
    void setHistogram(const cv::MatND &histogram_) {
        histogram = histogram_;
        // normalizing
        cv::normalize(histogram,histogram,1.0);
    }
    /********************************************************/

    /********************************************************/
    // 核心方法 find ， 反投影直方图，返回Mat
    cv::Mat find(const cv::Mat& image,
                 float minValue, float maxValue,
                 int *channels,int dim) {
        cv::Mat result;

        // 设置范围
        hranges[0] = minValue;
        hranges[1] = maxValue;

        for(int i= 0; i<dim; ++i)
            this->channels[i] = channels[i];

        //调用cv::calcBackProject 函数
        cv::calcBackProject(&image,1,
                            channels,
                            histogram,
                            result,
                            ranges,
                            255.0);

        // Threshold back projection to obtain the binary map
        if( threshold > 0.0)
            cv::threshold(result,result,255*threshold,255,cv::THRESH_BINARY);

        return result;
    }

    // 一下为补充函数，获取最后调用find 函数时的各个参数
    int* getChannels(){
        return channels;
    }
    float getMinValue() {
        std::cout << "hrange[0] : " << hranges[0] << std::endl;
        return hranges[0];
    }
    float getMaxValue() {
        std::cout << "hrange[1]: " << hranges[1] << std::endl;
        return hranges[1];
    }

};

#endif // CONTENTFINDER

