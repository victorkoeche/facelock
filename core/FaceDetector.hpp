#include<iostream>
#include<vector>

#include<opencv2/objdetect.hpp>

class FaceDetector {
public:
    FaceDetector();

    std::vector<cv::Rect> detect(const cv::Mat& image);

private:
    cv::CascadeClassifier classifier;
};