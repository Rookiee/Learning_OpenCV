#include <QCoreApplication>
#include "histogram1d.h"
#include <iostream>

using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::Mat image = cv::imread("/Users/Haoyang/Downloads/Pics/group.jpg",0);
    Histogram1D h;

    //hist 只是一个一维数组，包含256个元素
    cv::MatND hist = h.getHistogram(image);

    //显示原图
    namedWindow("原图");
    Mat imageSrc = imread("/Users/Haoyang/Downloads/Pics/group.jpg",0);
    imshow("原图",imageSrc);

    //loop over each bin
    for( int i = 0; i < 256; ++i) {
        std::cout << "Value " << i << ": " << hist.at<float>(i) << std::endl;
    }

    //调用图形化显示函数
    cv::namedWindow("HISTOGRAM1D");
    imshow("HISTOGRAM1D",
           h.getHistogramImage(image));

    /******************************************************************/
    // 调用 Histogram1D中的applyLookUp 函数
    namedWindow("LookUp-Table");
    imshow("LookUp-Table",h.applyLookUp(image,hist));
    /******************************************************************/
    /******************************************************************/
    //创建一个图像翻转表

    int dim = 256;
    cv::Mat lut(1,  //1 dimension
                &dim,   //256 entries
                CV_8U); //uchar
    for(int i= 0; i< 256; ++i) {
        lut.at<uchar>(i) = 255-i;
    }
    namedWindow("lut");
    imshow("lut",h.applyLookUp(image,lut));
    /******************************************************************/
     /******************************************************************/
    // 应用 stretch 函数
    image = imread("/Users/Haoyang/Downloads/Pics/group.jpg",0);
    namedWindow("Stretch");
    imshow("Stretch",h.stretch(image,100));
    // 显示将原直放图拉伸后的直方图
    namedWindow("Histogram After Stretch");
    imshow("Histogram After Stretch",h.getHistogramImage(h.stretch(image,100)));

    /******************************************************************/
     /******************************************************************/
    //应用 equalize函数，直方图拉伸
    namedWindow("Equalization");
    image = imread("/Users/Haoyang/Downloads/Pics/group.jpg",0);

    imshow("Equalization",h.equalize(image));
    //现实直方图
    namedWindow("Histogram After Equalization");
    imshow("Histogram After Equalization",h.getHistogramImage(h.equalize(image)));
    return a.exec();

    /******************************************************************/
    /******************************************************************/
    // BackProject Histogram 特区特定内容, 因为读取了新的图片，会使用新的变量名

//    cv::Mat imageCloud = imread("/Users/Haoyang/Downloads/waves.jpg",0);

//    // 获取ROI
//    cv::Mat cloudROI = imageCloud(cv::Rect(360,55,40,50));

//    // 提取ROI区域的直方图信息
//    Histogram1D hCloud;
//    cv::MatND histCloud = hCloud.getHistogram(cloudROI);

//    // normalizing this histogram
//    cv::normalize(histCloud,histCloud,1.0);

//    // 调用 calcBackProject 函数
//    cv::calcBackProject(&imageCloud,
//                        1,
//                        );

    //以上方法失败
    /******************************************************************/
    /******************************************************************/

}

