#include "filterProcessor.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <QDebug>
using namespace cv;


FilterProcessor::FilterProcessor()
    : useMedian(true)
    , useOpening(true)
    , useNoiseRecutiob(true)
    , bufferMode(false)
    , frameCount(0)
{
    pMOG2 = new cv::BackgroundSubtractorMOG(5000,0,0.1,0);
}

Mat FilterProcessor::process(const Mat &input){
    Mat binaryMask;
    Mat frame;
    if(bufferMode){
        if (frameCount!=0){
            input.convertTo(frame, -1, 2, 0);

            // perform filter

            binaryMask = filter(frame);

            if(useNoiseRecutiob){
               binaryMask=noiseRecution(binaryMask);
               bufferFrame=binaryMask;
            }

            if (useMedian){
                medianBlur(binaryMask, binaryMask, 5);
            }

            if (useOpening){
                erode(binaryMask, binaryMask, Mat());
                dilate(binaryMask, binaryMask, Mat());
            }

            frameCount=frameCount+1;
            return binaryMask;
        }else{
            frameCount=frameCount+1;
            if (frameCount==3){
                frameCount=0;
             }
            return bufferFrame;
        }
    }else{
        input.convertTo(frame, -1, 2, 0);

        // perform filter

        binaryMask = filter(frame);

        if(useNoiseRecutiob){
           binaryMask=noiseRecution(binaryMask);
           bufferFrame=binaryMask;
        }

        if (useMedian){
            medianBlur(binaryMask, binaryMask, 5);
        }

        if (useOpening){
            erode(binaryMask, binaryMask, Mat());
            dilate(binaryMask, binaryMask, Mat());
        }

        frameCount=frameCount+1;
        return binaryMask;
    }
   }
Mat FilterProcessor::filter(Mat& frame){

    Mat fgMaskMOG2;
    Mat frametoProcess;
    vector<Mat> channels;
    cvtColor(frame, frametoProcess, CV_BGR2YCrCb);
    split(frametoProcess,channels);
    equalizeHist(channels[0], channels[0]);
    merge(channels,frametoProcess);
    cvtColor(frametoProcess, frametoProcess, CV_YCrCb2BGR);
    pMOG2->operator ()(frametoProcess,fgMaskMOG2,0);
    return fgMaskMOG2;
}

Mat FilterProcessor::noiseRecution(Mat& binaryMask){
    Mat copyOfMask;
    binaryMask.copyTo(copyOfMask);

        // find all regions
        vector<vector<Point> >contours;
        findContours(copyOfMask, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

        // erase small regions

        for(int i = 0; i < contours.size(); i++){
            vector<Point>contour = contours[i];
            int area = contourArea(contour);
            if (area < 64){
                drawContours(binaryMask, contours, i, Scalar(0, 0, 0, 0), CV_FILLED);
            }
        }

       return binaryMask;

}

void FilterProcessor::setMedianEnable(bool enable){
    this->useMedian = enable;
}

void FilterProcessor::setOpeningEnable(bool enable){
    this->useOpening = enable;
}
