#include "cameracalibrator.h"

//CameraCalibrator::CameraCalibrator()
//{

//}


int CameraCalibrator::addChessboardPoints(const std::vector<std::__1::string> &fileList, cv::Size &boardSize)
{
    // the points on the chessboard
    std::vector<cv::Point2f> imageCorners;
    std::vector<cv::Point3f> objectCorners;

    // 3D Scene Points:
    // Initialize the chessboard corners
    // in the chessboard reference frame
    // The corners are at 3D location (X,Y,Z) = (i,j,0)
    for( int i = 0; i < boardSize.height; ++i) {
        for( int j = 0; j < boardSize.width; ++j) {
            objectCorners.push_back(cv::Point3f(i,j,0.0));
        }
    }

    // 2D image points:
    cv::Mat image; // to contain chessboard image
    int successes = 0;
    // for all viewpoints
    for(int i = 0; i < fileList.size(); ++i) {
        // Open the image
        image = cv::imread(fileList[i],0);
        // Get the chessboard corners
        bool found = cv::findChessboardCorners(image,
                                               boardSize,
                                               imageCorners);
        // Get subpixel accuracy on the corners
        cv::cornerSubPix(image,imageCorners,
                         cv::Size(5,5),
                         cv::Size(-1,-1),
                         cv::TermCriteria(cv::TermCriteria::MAX_ITER +
                                          cv::TermCriteria::EPS,
                                          30,
                                          0.1));
        // If we have a good board, add it to our data
        if(imageCorners.size() == boardSize.area()) {
            // add image and scene points from one view
            addPoints(imageCorners,objectCorners);
            successes ++;

        }

        // Draw the corners
        cv::drawChessboardCorners(image,boardSize,imageCorners,found);
        cv::imshow("Corners on Chessboard",image);
        cv::waitKey(100);
    }
    return successes;
}

void CameraCalibrator::addPoints(const std::vector<cv::Point2f> &imageCorners, const std::vector<cv::Point3f> &objectCorners)
{
    // 2D image points from one view
    imagePoints.push_back(imageCorners);
    // correspoding 3D scene points
    objectPoints.push_back(objectCorners);
}

double CameraCalibrator::calibrate(cv::Size imageSize)
{
    // undistorter must be reinitialized
    mustInitUndistort = true;
    // Output rotations and translations
    std::vector<cv::Mat> rvecs, tvecs;
    // start calibration
    return
            cv::calibrateCamera(objectPoints,
                                imagePoints,
                                imageSize,
                                cameraMatrix,
                                distCoeffs,
                                rvecs,tvecs,
                                flag);

}

cv::Mat CameraCalibrator::remp(const cv::Mat &image)
{
    cv::Mat undistorted;
    if(mustInitUndistort) {
        cv::initUndistortRectifyMap(cameraMatrix,
                                    distCoeffs,
                                    cv::Mat(),
                                    cv::Mat(),
                                    cv::Size(640,480),
                                    CV_32FC1,
                                    map1,map2);
        mustInitUndistort = false;
    }
    cv::remap(image,undistorted,map1,map2,
              cv::INTER_LINEAR); // interpolation type
    return undistorted;
}

void CameraCalibrator::setCalibrationFlag(bool radial8CoeffEnabled, bool tangentialParamEnabled)
{
    // set the flag used in cv::calibrateCamera()
    flag = 0;
    if(!tangentialParamEnabled) flag += CV_CALIB_ZERO_TANGENT_DIST;
    if(radial8CoeffEnabled) flag += CV_CALIB_RATIONAL_MODEL;
}


