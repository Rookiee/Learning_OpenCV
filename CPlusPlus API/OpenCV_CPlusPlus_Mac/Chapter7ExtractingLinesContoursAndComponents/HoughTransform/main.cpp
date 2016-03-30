#include <QCoreApplication>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// because the output of cv::HoughLines is a vector of cv::Vec3f,
// so <vector> must be included
#include <vector>

// Due to the use of sin, cos and PI, 'cmath' is needed.
#include <cmath>

// 最后失败了。。。。。。
/*
 * First, using Canny operator to obtain contours,
 * then, using hough transfomr the detect lines
 */
using namespace std;
using namespace cv;
typedef vector<cv::Vec2f> ::const_iterator Iter;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const double PI = 3.1415926;
    // Open an image with gray-level
    Mat imageSrc = imread("/Users/Haoyang/Downloads/Pics/road.jpg",0);
    if(imageSrc.empty()) {
        cerr << "你妹，出错了" << endl;
        return 1;
    }
    // Show original image
    namedWindow("Original");
    imshow("Original",imageSrc);

    // First, using 'canny operator' to obtain contours,
    Mat contours;
    cv::Canny(imageSrc,
              contours,
              128,
              350);
    // show contours for test
    namedWindow("Contours");
    imshow("Contours",contours);


    // Now, variable 'contours' contain the contour, however,
    // we need to invert black and white by threshold
    // invert
    Mat contoursInv;
    cv::threshold(contours,contoursInv,128,255,cv::THRESH_BINARY_INV);
    // Now, contoursInv is the one I can us to implement Hough Transform
    // show contoursInv for test
    namedWindow("ContoursInv");
    imshow("ContoursInv",contoursInv);

    // Hough Transform for line detection
    vector<cv::Vec2f> lines;
    cv::HoughLines(contoursInv,
                   lines,
                   1,
                   PI/180,
                   80);



    // The following codes are for test, to display the lines vector

//    int i = 1;
//    for(Iter iter= lines.begin(); iter != lines.end(); ++i,++iter) {
//        cout << i << " : ";
//        cout << *iter << endl;
//    }



    // look at the above testing code, we need to visulize them
    Iter iter = lines.begin();
    while (iter != lines.end()) {
        float rho = (*iter)[0];     // first element is distance rho
        float theta = (*iter)[1];   // second element is angle theta
        if ( theta < PI/4. ||
             theta > 3.*PI/4.) {    // vertical line
            //point of intersection of the line wiht first row
            cv::Point pt1(rho/cos(theta),0);
            cv::Point pt2((rho-imageSrc.rows*sin(theta)) /
                          cos(theta), imageSrc.rows);
            // draw a white line
            cv::line(imageSrc,pt1,pt2,cv::Scalar(189),1);
        }
        else {
            // point of intersection of the line with first column
            cv::Point pt1(0,rho/sin(theta));
            // point of intersection of the line wiht last column
            cv::Point pt2(imageSrc.cols,
                          (rho-imageSrc.cols * cos(theta))/sin(theta));
            // draw a white line
            cv::line(imageSrc,pt1,pt2,cv::Scalar(128),1);

        }
        ++iter;
    }

    // show the result
    namedWindow("Result");
    imshow("Result",imageSrc);


//    cv::Mat test(200,200,CV_8U,cv::Scalar(0));
//        cv::line(test,cv::Point(100,0),cv::Point(200,200),cv::Scalar(255));
//        cv::line(test,cv::Point(0,50),cv::Point(200,200),cv::Scalar(255));
//        cv::line(test,cv::Point(0,200),cv::Point(200,0),cv::Scalar(255));
//        cv::line(test,cv::Point(200,0),cv::Point(0,200),cv::Scalar(255));
//        cv::line(test,cv::Point(100,0),cv::Point(100,200),cv::Scalar(255));
//        cv::line(test,cv::Point(0,100),cv::Point(200,100),cv::Scalar(255));

//        // Display the test image
//        cv::namedWindow("Test Image");
//        cv::imshow("Test Image",test);
//        cv::imwrite("test.bmp",test);
    return a.exec();
}

