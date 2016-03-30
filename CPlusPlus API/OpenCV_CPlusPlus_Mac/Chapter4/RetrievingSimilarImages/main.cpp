#include <QCoreApplication>

#include "colorhistogram.h"
#include "imagecomparator.h"

#include <opencv2/highgui/highgui.hpp>
#include <iostream>

// 用循环，比较三个图像
#include <vector>

using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /************** Test ColorReduction in ColorHistogram class ********/
    /*
    Mat image = imread("/Users/Haoyang/Downloads/Pics/boldt.jpg");
    ColorHistogram testH;
    cv::namedWindow("Test");
    imshow("Test",testH.colorReduce(image));
    return a.exec();
    */


    /************** Test Goes Ahead **********************************/
    typedef vector<cv::Mat>::iterator Iter;
    typedef vector<string>::iterator IterStr;

    string path = "/Users/Haoyang/Downloads/Pics/";
    string string = path + "waves.jpg";
    cout << string << endl;
//    ImageComparator *comparator = new ImageComparator;
    ImageComparator comparator;
    vector<std::string> fileName;

//    fileName.push_back(path + "waves.jpg");
//    fileName.push_back(path + "beach.jpg");
//    fileName.push_back(path + "boldt.jpg");
    fileName.push_back(path + "1.bmp");
    fileName.push_back(path + "2.bmp");

    vector<cv::Mat> fileNameImage;
    for(IterStr it = fileName.begin(); it != fileName.end(); ++it) {
        fileNameImage.push_back(imread(*it));
    }

    double score;
    // 设置比较的图像
    comparator.setReferenceImage(fileNameImage[0]);
    namedWindow("Reference");
    imshow("Reference",fileNameImage[0]);

    // 输出 reference 的大小
    long unsigned int size = fileNameImage[0].rows * fileNameImage[0].cols;
    cout << "Reference 的大小(像素数) 是： " << size << "; "
         << "如果一下结果等于 " << size << " 则说明待比较的图像和reference相同" << endl;

    /*
    // 开始比较
    for(Iter it = fileNameImage.begin(); it != fileNameImage.end(); ++it) {
        score = comparator.compare(*it);
        cout << score << endl;
    }
    */

    Iter itImage = fileNameImage.begin();
    IterStr itName = fileName.begin();
    while( itImage != fileNameImage.end() ||
           itName != fileName.end()) {
        score = comparator.compare(*itImage);
        cout << *itName << " = " << score << endl;
        ++itImage;  ++itName;
    }

    return a.exec();



}

