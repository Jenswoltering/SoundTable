#ifndef FILTERPROCESSOR_H
#define FILTERPROCESSOR_H

#include "videoprocessor.h"

class FilterProcessor : public VideoProcessor
{
public:
    FilterProcessor();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void setMedianEnable(bool enable);
    void setOpeningEnable(bool enable);
private:
    cv::Mat filter(cv::Mat& hsvFrame);
    cv::Mat noiseRecution(cv::Mat& binaryMask);
    cv::Vec3b getAvgPixel(cv::Mat& hsvFrame);
private:
    cv::Point center;
    int frameCount;
    int avgCalcTime;
    int avgDistanceThreshold;
    int noiseAreaSize;
    bool useMedian;
    bool useOpening;
    bool useNoiseRecutiob;
};

#endif // COLORKEYERHSV_H
