#include <QCoreApplication>
#include "cameracalibrator.h"
#include <opencv2/features2d/features2d.hpp>
#include <string>
#include <iomanip>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::namedWindow("Image");
    cv::Mat image;
    std::vector<std::string> fileList;
    // generate list of chessboard image filename
    for(int i = 1; i < 20; ++i) {
        std::stringstream str;
        str << "/Users/Haoyang/Downloads/Pics/chessboards/chessboard" << std::setw(2) << std::setfill('0') << i << ".jpg";
        std::cout << str.str() << std::endl;

        fileList.push_back(str.str());
        image = cv::imread(str.str(),0);
        cv::imshow("Image",image);
        cv::waitKey(100);
    }

    // Create calibrator object
    CameraCalibrator cameraCalibrator;
    // add the corners from the chessboard
    cv::Size boardSize(6,4);
    cameraCalibrator.addChessboardPoints(fileList,
                                         boardSize);
    // calibrate the camera
    // cameraCalibrator.setCalibrationFlag(true,true);

    cameraCalibrator.calibrate(image.size());

    // Image Undistortion
    image = cv::imread(fileList[6]);
    cv::Mat uImage = cameraCalibrator.remp(image);

    // display camera matrix
    cv::Mat cameraMatrix = cameraCalibrator.getCameraMatrix();
    std::cout << "Camera Intrinsic: " << cameraMatrix.rows << "x" << cameraMatrix.cols << std::endl;
    std::cout << cameraMatrix.at<double>(0,0) << " " << cameraMatrix.at<double>(0,1) << " " << cameraMatrix.at<double>(0,2) << std::endl;
    std::cout << cameraMatrix.at<double>(1,0) << " " << cameraMatrix.at<double>(1,1) << " " << cameraMatrix.at<double>(1,2) << std::endl;
    std::cout << cameraMatrix.at<double>(2,0) << " " << cameraMatrix.at<double>(2,1) << " " << cameraMatrix.at<double>(2,2) << std::endl;

    cv::Mat diff = cameraCalibrator.getDistCoeffs();
    std::cout << "Diff" << diff.rows << "x" << diff.cols<< std::endl;
    std::cout << diff.at<double>(0,0) << " "
              << diff.at<double>(0,1) << " "
              << diff.at<double>(0,2) << " "
              << diff.at<double>(0,3) << " "
              << diff.at<double>(0,4) << " " << std::endl;
    cv::imshow("Original Image",image);
    cv::imshow("Undistorted Image",uImage);

    cv::waitKey();
    return a.exec();
}

