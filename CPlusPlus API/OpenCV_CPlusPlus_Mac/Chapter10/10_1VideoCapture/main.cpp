#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "videoprocessor.h"

int main()
{
    // Open the video file
    cv::VideoCapture capture("/Users/Haoyang/Downloads/Pics/bike.avi");
    // check if video successfully opened
    if (!capture.isOpened())
        return 1;

    // Get the frame rate
    double rate= capture.get(CV_CAP_PROP_FPS);

    bool stop(false);
    cv::Mat frame; // current video frame
    cv::namedWindow("Extracted Frame");

    // Delay between each frame
    // corresponds to video frame rate
    int delay= 1000/rate;

    // for all frames in video
    while (!stop) {

        // read next frame if any
        if (!capture.read(frame))
            break;

        cv::imshow("Extracted Frame",frame);

        // introduce a delay
        // or press key to stop
        if (cv::waitKey(delay)>=0)
                stop= true;
    }

    // Close the video file
    capture.release();

    cv::waitKey();

    // Now using the VideoProcessor class

    // Create instance
    VideoProcessor processor;
    // Open video file
    processor.setInput("../bike.avi");
    // Declare a window to display the video
    processor.displayInput("Input Video");
    processor.displayOutput("Output Video");
    // Play the video at the original frame rate
    processor.setDelay(1000./processor.getFrameRate());
    // Set the frame processor callback function
    processor.setFrameProcessor(canny);
    // Start the process
    processor.run();
    cv::waitKey();

    // Second test
    // Create instance
    //	VideoProcessor processor;
    // Open video file
    processor.setInput("../bike.avi");

    // Get basic info about video file
    cv::Size size= processor.getFrameSize();
    std::cout << size.width << " " << size.height << std::endl;
    std::cout << processor.getFrameRate() << std::endl;
    std::cout << processor.getTotalFrameCount() << std::endl;
    std::cout << processor.getFrameNumber() << std::endl;
    std::cout << processor.getPositionMS() << std::endl;

    // No processing
    processor.dontCallProcess();
    // Output filename
//	processor.setOutput("../output/bikeOut",".jpg");
    char codec[4];
    processor.setOutput("../output/bike.avi",processor.getCodec(codec),processor.getFrameRate());
    std::cout << "Codec: " << codec[0] << codec[1] << codec[2] << codec[3] << std::endl;

    // Position the stream at frame 300
    //	processor.setFrameNumber(300);
    //	processor.stopAtFrameNo(120);

    // Declare a window to display the video
    processor.displayInput("Current Frame");
    processor.displayOutput("Output Frame");

    // Play the video at the original frame rate
    processor.setDelay(1000./processor.getFrameRate());

    // Start the process
    processor.run();

    std::cout << processor.getFrameNumber() << std::endl;
    std::cout << processor.getPositionMS() << std::endl;

    cv::waitKey();
}

