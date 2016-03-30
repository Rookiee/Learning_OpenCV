#include <QCoreApplication>
#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const string path = "/Users/Haoyang/Downloads/Pics/";
    const double PI = 3.1415926;
    Mat img = imread(path + "road.jpg");
    Mat imgGray;
    cv::cvtColor(img,imgGray,cv::COLOR_BGR2GRAY);
    Mat edges;
    cv::Canny(imgGray,edges,128,350);
    cv::threshold(edges,edges,127,255,cv::THRESH_BINARY_INV);

    vector<cv::Vec4f> lines;
    typedef vector<cv::Vec4f>::iterator Iter;
    cv::HoughLines(edges,lines,1,PI/180,80);
    int i = 1;
    for(Iter it = lines.begin(); it != lines.end();++it,++i) {
        cout << i << ": ";
//        cout << (*it)[0] << "   ";
//        cout << (*it)[1] << "   ";
//        cout << (*it)[2] << "   ";
//        cout << (*it)[3] << "   " << endl;
    }

//    Iter iter = lines.begin();
//    while(iter !=lines.end()) {
//        float rho = (*iter)[0];
//        float theta = (*iter)[1];
//        if(theta < PI/4.0 || theta > 3.0*PI/4) {
//            cv::Point pt1(rho/cos(theta),0);
//            cv::Point pt2((rho-img.rows*sin(theta))/cos(theta),img.rows);
//            cv::line(img,pt1,pt2,(255,255,0),2);
//        }
//        else {
//            cv::Point pt1(0,rho/sin(theta));
//            cv::Point pt2(img.cols, (rho-img.cols*cos(theta))/sin(theta));
//            cv::line(img,pt1,pt2,(0,255,255),1);
//        }
//        ++iter;
//    }
    cv::namedWindow("gray");
    cv::imshow("gray",img);
    return a.exec();
}

