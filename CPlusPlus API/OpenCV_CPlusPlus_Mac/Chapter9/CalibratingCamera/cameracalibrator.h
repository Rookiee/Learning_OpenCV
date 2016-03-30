#ifndef CAMERACALIBRATOR_H
#define CAMERACALIBRATOR_H


#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <vector>
class CameraCalibrator
{
private:
    // 输入点
    // world coordinates 点
    std::vector< std::vector<cv::Point3f> > objectPoints;
    // the point position in pixels
    std::vector< std::vector<cv::Point2f> > imagePoints;

    // 输出矩阵
    cv::Mat cameraMatrix;
    cv::Mat distCoeffs;

    // flag to specify how calibration is done
    int flag;

    // used in image undistortion
    cv::Mat map1, map2;
    bool mustInitUndistort;

public:
    CameraCalibrator() : flag(0), mustInitUndistort(true) {}

    // Open chessboard images and extract corner points
    int addChessboardPoints(const std::vector<std::string>& fileList,
                            cv::Size &boardSize);
    // Add scene points and corresponding image points
    void addPoints(const std::vector<cv::Point2f> &imageCorners,
                   const std::vector<cv::Point3f>& objectCorners);

    // Calibrate the camera
    // return the re-projection error
    double calibrate(cv::Size imageSize);

    // Remove distortion in an image (after calibration)
    cv::Mat remp(const cv::Mat &image);

    // Setter: set the calibration flag
    void setCalibrationFlag(bool radial8CoeffEnabled=false,
                            bool tangentialParamEnabled = false);

    // Getter
    cv::Mat getCameraMatrix() { return cameraMatrix;}
    cv::Mat getDistCoeffs() { return distCoeffs;}
};

#endif // CAMERACALIBRATOR_H
