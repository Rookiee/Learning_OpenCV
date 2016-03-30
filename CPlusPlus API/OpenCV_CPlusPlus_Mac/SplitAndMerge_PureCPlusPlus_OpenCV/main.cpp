#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

bool imageSplit();

int main()
{
    imageSplit();
    cout << "Hello World!" << endl;
    return 0;
}

bool imageSplit() {
    vector<Mat> channel;
    Mat logo = imread("/Users/Haoyang/Downloads/girl.png");
    split(logo,channel);
    Mat imageROI = channel.at(1);

//    merge(channel,logo);

    namedWindow("Resule");
    imshow("Result",imageROI);
    waitKey();

    return true;
}

