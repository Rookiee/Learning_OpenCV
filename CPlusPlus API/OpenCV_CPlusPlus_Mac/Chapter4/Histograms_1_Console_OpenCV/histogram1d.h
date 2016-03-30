#ifndef HISTOGRAM1D
#define HISTOGRAM1D
#include <iostream>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//for cv::calcHist();
#include <opencv2/opencv.hpp>

/*00000000000000000000------BEGIN----0000000000000000000000000000*/
class Histogram1D {
private:
    //项bin的数量
    int histSize[1];
    //最大和最小像素值, float类型
    float hranges[2];

    const float * ranges[1];
    int channels[1]; //only 1 channel here

public:

    Histogram1D() {
        //prepare the arguments for 1D histogram
        histSize[0] = 256;  //包含256项，每一项的取值为0~255
        hranges[0] = 0.0;
        hranges[1] = 255.0;
        ranges[0] = hranges;
        channels[0] = 0;    // by default, we look at channel 0
       }
/******************************************************************/
    //调用 calcHist 计算直方图
    //Compute the 1D histogram
    cv::MatND getHistogram(const cv::Mat& image) {
        cv::MatND  hist;
        //compute histogram
        cv::calcHist(&image,
                     1,
                     channels,
                     cv::Mat(),
                     hist,
                     1,
                     histSize,
                     ranges);
        return hist;    //一个包含256个元素的一维数组
    }
/******************************************************************/
    //图形化显示
    cv::Mat getHistogramImage(const cv::Mat& image) {
        //compute the histogram first
        cv::MatND hist = getHistogram(image);
        //get min and max bin value
        double maxVal = 0;
        double minVal = 0;
        cv::minMaxLoc(hist,&minVal,&maxVal,0,0);

        //Image on which to display histogram
        cv::Mat histImage(histSize[0],histSize[0],CV_8U,cv::Scalar(255));

        //set highest point at 90% of nbins
        int hpt = static_cast<int>(0.9 * histSize[0]);

        //Draw a vertical line for each bin
        for (int h = 0; h<histSize[0]; ++h) {
            float binVal = hist.at<float>(h);
            int intensity = static_cast<int>(binVal*hpt/maxVal);

            // This function draw a line between 2 points
            cv::line(histImage,cv::Point(h,histSize[0]),
                    cv::Point(h,histSize[0] - intensity),
                    cv::Scalar::all(0));
        }
        return histImage;

    }

    /******************************************************************/
    //定义函数实现look-up table
    cv::Mat applyLookUp(const cv::Mat& image,   //输入图像
                        const cv::Mat & lookup) {   // 1*256 uchar matrix
         // 1*256 matrix, 这里获得的直方图hist，其实就是一个一维数组，包含256个元素
        // image for output
        cv::Mat result;
        cv::LUT(image,lookup,result);
        return result;


    }

    /******************************************************************/
    /******************************************************************/
    // 定义lookup table 增强对比度
    // stretch the histogram in order to produce an image with an
    // expanded contrast
    cv::Mat stretch(const cv::Mat& image, int minValue = 0) {
        // Compute histogram first
        cv::MatND hist = getHistogram(image);

        // 寻找直方图最左端
        int imin = 0;
        for(; imin != histSize[0]; ++imin ){
            std::cout << imin << ": " << hist.at<float>(imin) << std::endl;
            if(hist.at<float>(imin) > minValue)
                break;
        }
        std::cout << "***********" << std::endl;
        // 寻找直方图最右端
        int imax = histSize[0] - 1;
        for(; imax != -1; --imax ) {
            std::cout << imax << ": " << hist.at<float>(imax) << std::endl;
            if(hist.at<float>(imax) > minValue)
                break;
        }

        // Create lookup table
        // lookup 需 1*256 matrix
        int dim(256);
        cv::Mat lookup(1, dim, CV_8U);      //lookup
        // Build the table
        for(int i = 0; i< dim; ++i) {
            // 在imin 和 imax 之间，将直方图拉伸
            if(i < imin)
                lookup.at<uchar>(i) = 0;
            else if(i > imax)
                lookup.at<uchar>(i) = 255;
            else
                lookup.at<uchar>(i) = 255.0 * (i-imin)/(imax-imin) + 0.5;
        }

        // Apply this lookup-table
        cv::Mat result;
        result = applyLookUp(image,lookup);
        return result;

    }
    /******************************************************************/
    /******************************************************************/
    // Histogram Euqliazation
    cv::Mat equalize(const cv::Mat& image) {
        cv::Mat result;
        cv::equalizeHist(image,result);
        return result;
    }

    /******************************************************************/
    /******************************************************************/
    // BackProject Histogram 特区特定内容
    // 直接在main中实现
    }
};

/*00000000000000000000------END----0000000000000000000000000000*/



/*------------------------一下为彩色图像的直方图------------------------------*/
//重新定义一个类
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

        ranges[0] = hranges;    // all channels have the same range
        ranges[1] = hranges;
        ranges[2] = hranges;

        channels[0] = 0;
        channels[0] = 1;
        channels[2] = 2;

    }

    /******************************************************************/
    cv::SparseMat getHistogram(const cv::Mat & image){
        cv::SparseMat hist(3,histSize,CV_32F);  //稀疏矩阵
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
};

#endif // HISTOGRAM1D

