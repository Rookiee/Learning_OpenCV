#ifndef REDUCECOLOR
#define REDUCECOLOR
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

void colorReduce(cv::Mat &image, int div=64) {
    int nr = image.rows;    // 获得图像行数
    // 获取 每一行中包含的元素个数，cols 获取每列的像素数，
    // 每个像素又包含3个通道，所以，
    int nl = image.cols * image.channels();

    for( int j = 0; j < nr; ++j) {
        // get the address of row j
        uchar *data = image.ptr<uchar>(j);
        for(int i= 0; i< nl; i++) {
            //处理每个像素
            data[i] = data[i]/div*div + div/2;
            //处理结束
        }
    }
}

#endif // REDUCECOLOR

