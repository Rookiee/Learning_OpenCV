#ifndef COLORHISTOGRAM
#define COLORHISTOGRAM

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

// 需要把hsv的三个通道分开，每个通道为一张图像，
// 保存在<vector><cv::Mat> 的一个元素中
#include <vector>


class ColorHistogram {
private:
    int histSize[3];
    float hranges[2];
    const float * ranges[3];
    int channels[3];
public:
    ColorHistogram() {
        histSize[0] = histSize[1] = histSize[2] = 256;
        hranges[0] = 0.0;
        hranges[1] = 255.0;

        ranges[0] = hranges;
        ranges[1] = hranges;
        ranges[2] = hranges;

        channels[0] = 0;
        channels[1] = 1;
        channels[2] = 2;
    }

    cv::MatND getColorHistogram(const cv::Mat &image) {
        cv::MatND hist(3,histSize,CV_32F);
        //compute histogram
        cv::calcHist(&image,
                     1,
                     channels,
                     cv::Mat(),
                     hist,
                     3,
                     histSize,
                     ranges);
        return hist;

    }

    /************************************************************/
    /***************新增一个方法，实现获取 hue histogram ************/
    /*------------ 使用 Mean Shift  （均值漂移）方法---------------*/
    // compute the 1D Hue histogram with a mask
    // BGR source image is needed to converted to HSV
    // Pixels with low saturation are ignored
    cv::MatND getHueHistogram(const cv::Mat &image,
                              int miniSaturation = 0) {
        // 输出的结果，可作为ContendFinder类的输入
        cv::MatND hist;

        // Convert to HSV color space
        cv::Mat hsv;
        cv::cvtColor(image,hsv,CV_BGR2HSV);

        // Mask to be used (or not)
        cv::Mat mask;
        if(miniSaturation > 0) {
            // spliting the 3 channels into 3 image
            std::vector<cv::Mat> v;
            cv::split(hsv,v);
            // Mask out the low saturation pixels
            cv::threshold(v[1], // input
                    mask, //output, 注意，mask是函数输出,
                          // 在下面输出mask看一下
                    miniSaturation,
                    255,cv::THRESH_BINARY);

            /**********  TEST BEGIN **********/
            cv::namedWindow("Temp for Mask");
            imshow("Temp for Mask",mask);
            /**********  TEST END ************/
        }

        // prepare arguments for 1D hue histogram
        hranges[0] = 0.0;
        hranges[1] = 180.0;

        channels[0] = 0;    // the hue channel

        // Compute the histogram
        cv::calcHist(&hsv,1,
                     channels,  // the channel used
                     mask,      // binary mask
                     hist,      // the resulting
                     1,         // it's 1D histogram
                     histSize,  // number of bins
                     ranges     // pixel value range
                     );
        return hist;
    }

    // 补充方法，为了获取channle[0] 这个通道，在main函数mean shift的实现的find函数中
    // 要使用
    int *getChannel() {
        return channels;
    }

};

#endif // COLORHISTOGRAM

