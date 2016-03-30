#include <QCoreApplication>
//For OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
using namespace std;
using namespace cv;

bool ROI_Blending();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(ROI_Blending())
        cout << "看到了吧" << endl;
    waitKey();
    return a.exec();
}

bool ROI_Blending() {
    Mat image = imread("/Users/Haoyang/Downloads/boldt.jpg");
    Mat logo = imread("/Users/Haoyang/Downloads/logo.bmp");
    if(!image.data)
        cout << "你大爷，没读到image" << endl;
    if(!logo.data)
        cout << "你大爷,没读到logo" << endl;

    //定义Region of Interest 区域
    Mat ROIMage = image(Rect(100,100,logo.cols,logo.rows));

    //定义MASK

    Mat mask = imread("/Users/Haoyang/Downloads/logo.bmp",0);

    //把mask应用到ROI,
    logo.copyTo(ROIMage,mask);


    /*************************************************/
    //读入rain， 将rain 和boldt 线性混合
    Mat rain = imread("/Users/Haoyang/Downloads/rain.jpg");
    addWeighted(image,0.5,rain,0.5,0,image);
    /*************************************************/



    /*************************************************/

    //将logo加到原图上,
    //ROIMage是ROI，也就是将logo放在ROIMage上（通过线性混合放入）
    addWeighted(ROIMage,1,logo,0.5,0.0,ROIMage);

    /*************************************************/

    //显示结果
    namedWindow("ROI");
    imshow("ROI",image);

    waitKey();

    return true;



}
