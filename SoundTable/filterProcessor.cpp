#include "filterProcessor.h"
#include <QDebug>
using namespace cv;


FilterProcessor::FilterProcessor()
    : useMedian(true)
    , useOpening(true)
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
      qDebug() << "hue: " << avgPixel[0];
      qDebug() << "sat: " << avgPixel[1];
      qDebug() << "val: " << avgPixel[2];
      avgPixel[2]=avgPixel[2]-(avgPixel[0]/100*15);

    }

    for(int x = 0; x < hsvFrame.cols; x++){
        for(int y = 0; y < hsvFrame.rows; y++){
            Vec3b hsvPixel = hsvFrame.at<Vec3b>(y,x);
            int hue = hsvPixel[0];
            int saturation = hsvPixel[1];
            int value = hsvPixel[2];

            bool isWhite = false;

            if (hue<=avgPixel[0]){

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
    Vec3b avgPixel;
    int avgHue = 0;
    int avgSat=0;
    int avgVal=0;

    for(int x = 0; x < hsvFrame.cols; x++){
        for(int y = 0; y < hsvFrame.rows; y++){
            avgHue=avgHue+hsvFrame.at<Vec3b>(y,x)[0];
            avgSat=avgSat+hsvFrame.at<Vec3b>(y,x)[1];
            avgVal=avgVal+hsvFrame.at<Vec3b>(y,x)[2];
        }
    }
    avgHue=avgHue/(hsvFrame.cols*hsvFrame.rows);
    avgSat=avgSat/(hsvFrame.cols*hsvFrame.rows);
    avgVal=avgVal/(hsvFrame.cols*hsvFrame.rows);
    avgPixel[0]=avgHue;
    avgPixel[1]=avgSat;
    avgPixel[2]=avgVal;

    return avgPixel;
}

void FilterProcessor::setMedianEnable(bool enable){
    this->useMedian = enable;
}

void FilterProcessor::setOpeningEnable(bool enable){
    this->useOpening = enable;
}
