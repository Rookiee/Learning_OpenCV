#ifndef LINEFINDER
#define LINEFINDER

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#define PI 3.1415926

class LineFinder {
private:
    // original image
    cv::Mat img;
    
    // vector containing the end points of the detected lines
    std::vector<cv::Vec4i> lines;
    
    // accumulator resolution parameter
    double deltaRho;
    double deltaTheta;
    
    // minimum number of votes that a line must receive before being considered.
    int minVote;
    
    // min length for a line
    double minLenght;
    
    // max allowed gap along the line
    double maxGap;
    
public:
    LineFinder() : deltaRho(1), deltaTheta(PI/180),
        minVote(10),minLenght(0.), maxGap(0.) {}
    
    // Set the resolution of the accumulator
    void setAccResolution(double dRho, double dTheta) {
        deltaRho = dRho;
        deltaTheta = dTheta;
    }
    
    // set minimum vote
    void setMinVote(int min) {
        minVote = min;
    }
    
    // set length and gap
    void setLineLengthAndGap(double length, double gap) {
        minLenght = length;
        maxGap = gap;
    }
    
    /********************************************************/
    
    // Apply probabilistic Hough Transform
    std::vector<cv::Vec4i> findLines(cv::Mat& binary) {
        lines.clear();
        cv::HoughLinesP(binary,lines,deltaRho,deltaTheta,minVote,
                        minLenght,maxGap);
        return lines;
    }
    
    // Draw the detected lines on an image
    void drawDetectedLines(cv::Mat &image,cv::Scalar color = cv::Scalar(255,255,255)) {
        // Draw the lines
        std::vector<cv::Vec4i>::const_iterator it = lines.begin();
        while( it != lines.end()) {
            cv::Point pt1((*it)[0],(*it)[1]);
            cv::Point pt2((*it)[2],(*it)[3]);
            
            cv::line(image,pt1,pt2,color);
            ++it;
        }
    }
};

#endif // LINEFINDER

