#ifndef FILTERPROCESSOR_H
#define FILTERPROCESSOR_H

#include "videoprocessor.h"
using namespace cv;
using namespace std;

class FilterProcessor : public VideoProcessor
{
public:
    FilterProcessor();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void setMedianEnable(bool enable);
    void setOpeningEnable(bool enable);
private:
    cv::Mat filter(cv::Mat& input);
    cv::Mat noiseRecution(cv::Mat& binaryMask);
private:
    cv::Point center;
    bool useMedian;
    bool useOpening;
    bool useNoiseRecutiob;
    bool bufferMode;
    cv::Mat bufferFrame;
    int frameCount;
    Ptr<BackgroundSubtractor> pMOG2;

};

#endif // COLORKEYERHSV_H
