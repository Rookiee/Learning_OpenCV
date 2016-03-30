#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

void sharpen(const cv::Mat& image, cv::Mat& result)
{
    //allocate if necessary
    result.create(image.size(),image.type());

    for(int j= 1; j < image.rows-1; ++j) { // for all rows
                                // except the first and last row
        const uchar* previous =
                image.ptr<uchar>(j-1);
        const uchar* current =
                image.ptr<uchar>(j);
        const uchar* next =
                image.ptr<uchar>(j+1);

        uchar* output = result.ptr<uchar>(j); // output row

        for(int i= 1; i < (image.cols-1) * image.channels(); ++i) {
            // stature_cast: avoid the mathematical expression applied on the pixels leads to a
            // result that goes out of the range of the permited pixel value( 0 - 255)
            *output ++ = cv::saturate_cast<uchar>(5 * current[i] - current[i-1] - current[i+1] -
                         previous[i] - next[i]);
        }
    }


        //set the unprocess pixels to zero
        result.row(0).setTo(cv::Scalar(0));
        result.row(result.rows-1).setTo(cv::Scalar(0));
        result.col(0).setTo(cv::Scalar(0));
        result.col(result.cols-1).setTo(cv::Scalar(0));

}

void sharpen2D(const cv::Mat& image, cv::Mat& result) {
    // Construct kernel( all entries initilized to 0
    cv::Mat kernel(3,3,CV_32F,cv::Scalar(0));
    // assign kernel value
    kernel.at<float>(1,1) = 5.0;
    kernel.at<float>(0,1) = -1.0;
    kernel.at<float>(2,1) = -1.0;
    kernel.at<float>(1,0) = -1.0;
    kernel.at<float>(1,2) = -1.0;

    //filter the image
    cv::filter2D(image,result,image.depth(),kernel);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::Mat image = cv::imread("/Users/Haoyang/Downloads/boldtgray.jpg");
    cv::Mat result;
    sharpen(image,result);
    cv::namedWindow("sharpen");
    imshow("sharpen",result);


    cv::namedWindow("2D");
    sharpen2D(image,result);
    imshow("2D",result);


    return a.exec();
}


