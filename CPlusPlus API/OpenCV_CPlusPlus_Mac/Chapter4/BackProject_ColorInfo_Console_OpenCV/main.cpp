#include <QCoreApplication>

#include "contentfinder.h"
#include "reducecolor.h"
#include "colorhistogram.h"

#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
/*

    //创建ColorHistogram 对象
    ColorHistogram ch;

    // load the image
    Mat image = imread("/Users/Haoyang/Downloads/Pics/waves.jpg");

    namedWindow("Origianl");
    imshow("Original",image);

    if(image.data) {
        // reduce color
        colorReduce(image,32);
        // set ROI
        Mat blueROI = image(Rect(0,0,165,75));

        namedWindow("ROI");
        imshow("ROI",blueROI);

        // compute the histogram
        cv::MatND hist = ch.getColorHistogram(blueROI);
        // 创建ContentFinder 对象
        ContentFinder *finder = new ContentFinder;
        finder->setHistogram(hist);
        finder->setThreshold(0.05f);

//        std::cout << finder->getThreshold() << std::endl;
        std::cout << finder->getMinValue() << std::endl;
        std::cout << finder->getMaxValue() << std::endl;


        // Get back-projection of color histgram

        cv::Mat result = finder->find(image,finder->getMinValue(),
                                      finder->getMaxValue(),finder->getChannels(),
                                      3);
        namedWindow("Result");
        imshow("Result",result);

    }
    else
        std::cerr << "你妹，读文件出错！" << std::endl;

*/
    /*****************************************************************/
    /********************** MEAN SHIFT ALGORITHM *********************/

    // 读入第一张图片
    Mat image1 = imread("/Users/Haoyang/Downloads/Pics/baboon1.jpg");
    // 获取脸部，作为ROI
    Mat image1ROI = image1(Rect(110,260,35,40));
//    namedWindow("temp",cv::WINDOW_AUTOSIZE);
//    imshow("temp",image1ROI);

    // Get the hue histogram
    int minSat = 65;
    ColorHistogram hc;
    cv::MatND colorhist = hc.getHueHistogram(image1ROI,minSat);
    
    ContentFinder *finder = new ContentFinder;
    // 将得到的脸部的 1D hue histogram作为参数输入，
    // 用来设置ContentFinder 的私有变量
    finder->setHistogram(colorhist);
    
    // 打开第二张图像
    Mat image2 = imread("/Users/Haoyang/Downlaods/Pics/baboon2.jpg");
    // Convert to hsv color space
    Mat hsv;
    cv::cvtColor(image2, hsv,CV_BGR2HSV);
    // split the image
    std::vector<Mat> v;
    cv::split(image2,v);
    // Identify pixels with low saturation
    cv::threshold(v[1],v[1],minSat,255,cv::THRESH_BINARY);
    
    // next, obtain the back-projection of the hue channel of this image
    // using the previously obtained histogram
    // Get back - projection of hue histogram, using find method
    Mat result = finder->find(hsv,0.0f,180,hc.getChannel(),1);
    // Eliminate low staturation pixels
    cv::bitwise_and(result,v[1],result);

    Rect rect(110,260,35,40);
    cv::rectangle(image2,rect,cv::Scalar(0,0,255));
    TermCriteria criteria(TermCriteria::MAX_ITER,10,0.01);
//    cv::meanShift(result,rect,criteria);
    cv::meanShift(result,rect,criteria);

    namedWindow("Result");
    imshow("Result",result);


    
    return a.exec();
}

