#include "filterProcessor.h"
#include <QDebug>
using namespace cv;


FilterProcessor::FilterProcessor()
    : useMedian(false)
    , useOpening(false)
    , frameCount(0)
{
}

Mat FilterProcessor::process(const Mat &input){
    // convert BGR -> HSV
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);

    // perform color keying
    Mat binaryMask = filter(hsvFrame);
    frameCount=frameCount+1;
    if (frameCount==100){
        frameCount=0;
    }
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
Mat FilterProcessor::filter(Mat& hsvFrame){
    // initialize Mat object for output
    Mat output(hsvFrame.rows, hsvFrame.cols, CV_8UC1);
    Vec3b avgPixel;
    if (frameCount==0){
      Vec3b avgPixel = getAvgPixel(hsvFrame);
    }

    for(int x = 0; x < hsvFrame.cols; x++){
        for(int y = 0; y < hsvFrame.rows; y++){
            Vec3b hsvPixel = hsvFrame.at<Vec3b>(y,x);
            int hue = hsvPixel[0];
            int saturation = hsvPixel[1];
            int value = hsvPixel[2];

            bool isWhite = false;

            if (value<=avgPixel[2]){
                isWhite=true;
            }




            if (isWhite){
                output.at<uchar>(y,x) = 255;
            }
            else{
                output.at<uchar>(y,x) = 0;
            }
        }
    }
    return output;
}

Vec3b FilterProcessor::getAvgPixel(Mat& hsvFrame){
    Scalar avgPixel= cv::mean(hsvFrame);
    Mat helpHSV;
    Mat helpMat(1, 1, CV_8UC3,avgPixel);
    cvtColor(helpMat,helpHSV,CV_BGR2HSV);
    return helpHSV.at<Vec3b>(1,1);

}


void FilterProcessor::setMedianEnable(bool enable){
    this->useMedian = enable;
}

void FilterProcessor::setOpeningEnable(bool enable){
    this->useOpening = enable;
}
