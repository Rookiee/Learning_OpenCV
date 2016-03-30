#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <QDebug>

void salt(cv::Mat & image, int n = 64);
void ColorReduce(cv::Mat &image, int div);
void ColorRecuceIter(cv::Mat& image, int div);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::Mat image = cv::imread("/Users/Haoyang/Downloads/boldt.jpg");
//    cv::Mat image = cv::imread("/Users/Haoyang/Downloads/lena.jpg");
//    salt(image,3000);
//    cv::namedWindow("Show Image");
//    cv::imshow("Show Image",image);

    cv::namedWindow("Another");
//    ColorReduce(image, 64);
    double duration;
    duration = static_cast<double>(cv::getTickCount());
    ColorRecuceIter(image,64);
    duration = static_cast<double>(cv::getTickCount()) - duration;
    qDebug() << duration / cv::getTickFrequency(); // the elapsed time in ms
    unsigned rows = image.rows;
    unsigned cols = image.cols * image.channels();
    image.reshape(1, rows*cols);
    cv::imshow("Another",image);
    qDebug() << image.isContinuous();
    qDebug() << image.cols << " * " << image.rows;
    return a.exec();
}

void salt(cv::Mat &image, int n) {
    for(int k=0; k<n; k++) {
        int r = rand() % image.rows;
        int l = rand() % image.cols;
        if(image.channels() == 1) {
            image.at<uchar>(r,l) = 255;
        }
        else if(image.channels() == 3) {
            image.at<cv::Vec3b>(r,l)[0] = 255;
            image.at<cv::Vec3b>(r,l)[1] = 255;
            image.at<cv::Vec3b>(r,l)[2] = 255;
        }
    }
}

void ColorReduce(cv::Mat &image, int div=64)
{

    int rows = image.rows; // get the number of rows
    int cols = image.cols * image.channels(); // the number of elements in a line,
    if(image.isContinuous()) {
        cols = rows * cols;
        rows = 1;

    }
    for (int i = 0; i < rows; ++i) {
        uchar * data = image.ptr<uchar>(i);
        for(int j = 0; j < cols; ++j) {
            data[j] = data[j]/div * div + div/2;
        }
    }

}

void ColorRecuceIter(cv::Mat &image, int div) {
    //obtain iterator at initial position
    cv::Mat_<cv::Vec3b>::iterator iterBegin = image.begin<cv::Vec3b>() + 200;
    cv::Mat_<cv::Vec3b>::iterator iterEnd = image.end<cv::Vec3b>();

    //loop over all pixels
    for( ; iterBegin != iterEnd; ++iterBegin) {
        (*iterBegin)[0] = (*iterBegin)[0] / div * div + div/2;
        (*iterBegin)[1] = (*iterBegin)[1] / div * div + div/2;
        (*iterBegin)[2] = (*iterBegin)[2] / div * div + div/2;
    }

}
