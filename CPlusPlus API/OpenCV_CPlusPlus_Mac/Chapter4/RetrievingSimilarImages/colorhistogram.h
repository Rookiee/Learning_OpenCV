#ifndef COLORHISTOGRAM
#define COLORHISTOGRAM

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class ColorHistogram {
private:
    int histSize[3];
    float hranges[2];
    const float* ranges[3];
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
    /****************************************************************/
    /*-----------------------获取直方图-------------------------------*/
    cv::MatND getColorHistogram(const cv::Mat&image) {
        cv::MatND hist;
        // Compute histogram
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

    /****************************************************************/
    /*-----------------------获取稀疏矩阵-----------------------------*/
    cv::SparseMat getSparseHistogram(const cv::Mat& image){
        cv::SparseMat hist(3,histSize,CV_32F);

        // Compute histogram
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

    /****************************************************************/
    /*-----------------------降低颜色空间-----------------------------*/
    /* to get a reliable similarity measures,
     * the number of colors must be reduced.
     * (  try it without colorReduce(), either )
    */
    cv::Mat colorReduce(const cv::Mat& image, int div = 32) {
        cv::Mat result = image;
        // get lines
        int rows = image.rows;
        // get every element in a line
        int cols = image.cols * image.channels();

        for(int iRow = 0; iRow < rows; ++iRow) {
            // get the address of iRow
            uchar *data = result.ptr<uchar>(iRow);
            for (int iCol = 0; iCol <  cols ; ++iCol) {
                // processing method
                data[iCol] = data[iCol]/div * div + div/2;
            }
        }
        return result;
    }
};

#endif // COLORHISTOGRAM

