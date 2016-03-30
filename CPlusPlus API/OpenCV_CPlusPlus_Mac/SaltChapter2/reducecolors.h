#ifndef REDUCECOLORS_H
#define REDUCECOLORS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

cv::Mat & ColorReduce(cv::Mat &image, int div)
{
    int rows = image.rows; // get the number of rows
    int cols = image.cols * image.channels(); // the number of elements in a line, the cols

    for (int i = 0; i < rows; ++i) {
        uchar * data = image.ptr<uchar>(i);
        for(int j = 0; j < cols; ++j) {
            data[j] = data[j]/div * div + div/2;
        }
    }

    return image;

}


#endif // REDUCECOLORS_H

