#include <QCoreApplication>
#include "colordetector.h"

using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mat image = imread("/Users/Haoyang/Downloads/boldt.jpg");
    namedWindow("Result");
    ColorDetector detector;
    detector.setTargetColor(1,1,1);
    Mat processedImage = detector.Process(image);
    imshow("Result",processedImage);
    waitKey();

    return a.exec();
}

