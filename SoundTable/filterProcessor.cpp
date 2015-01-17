#include "filterProcessor.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <QDebug>
using namespace cv;


FilterProcessor::FilterProcessor()
    : useMedian(false)
    , useOpening(false)
{
    pMOG2 = new cv::BackgroundSubtractorMOG2(25,16,false);
}

Mat FilterProcessor::process(const Mat &input){
    // convert BGR -> HSV

    Mat hsvFrame;
    Mat frame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);
    frame=input;
    // perform color keying
    Mat binaryMask = filter(frame);


    if (useMedian){
        medianBlur(binaryMask, binaryMask, 5);
    }

    if (useOpening){
        erode(binaryMask, binaryMask, Mat());
        dilate(binaryMask, binaryMask, Mat());
    }


    // convert binary Image to 3 channel image
    Mat output;
    cvtColor(binaryMask, output, CV_GRAY2BGR);


    return output;
}
Mat FilterProcessor::filter(Mat& frame){
/*
    // initialize Mat object for output

    Mat output(hsvFrame.rows, hsvFrame.cols, CV_8UC1);

   for(int x = 0; x < hsvFrame.cols; x++){
        for(int y = 0; y < hsvFrame.rows; y++){
            Vec3b hsvPixel = hsvFrame.at<Vec3b>(y,x);


           // Maskierung und Schwerpunktsberechnung
            bool isWhite = false;

            if (isWhite){
               output.at<uchar>(y,x) = 255;
            }
            else{
                output.at<uchar>(y,x) = 0;
            }
        }
    }
 */

    Mat fgMaskMOG2;
    Mat frametoProcess;
    frametoProcess=frame;
    pMOG2->operator ()(frametoProcess,fgMaskMOG2,0.1);
    return fgMaskMOG2;
}



void FilterProcessor::setMedianEnable(bool enable){
    this->useMedian = enable;
}

void FilterProcessor::setOpeningEnable(bool enable){
    this->useOpening = enable;
}
