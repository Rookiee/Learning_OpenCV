#include <QCoreApplication>
#include <opencv2/highgui/highgui.hpp>
#include "linefinder.h"
#include <QDebug>

using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mat image = imread("/Users/Haoyang/Downloads/Pics/road.jpg",0);
    if(!image.data) {
        qDebug() << "你妹";
        return 1;
    }

    Mat contours;
    cv::Canny(image,
              contours,
              125,
              350);
    namedWindow("Contours");
    imshow("Contours",contours);

    LineFinder *finder = new LineFinder;
    
    finder->setLineLengthAndGap(100,20);
    finder->setMinVote(80);
    
    std::vector<cv::Vec4i> lines = finder->findLines(contours);
    finder->drawDetectedLines(image);

    namedWindow("Draw");
    imshow("Draw",image);

    return a.exec();
}

