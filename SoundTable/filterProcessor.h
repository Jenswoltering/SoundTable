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
private:
    cv::Point center;
    bool useMedian;
    bool useOpening;
    Ptr<BackgroundSubtractor> pMOG2;

};

#endif // COLORKEYERHSV_H
