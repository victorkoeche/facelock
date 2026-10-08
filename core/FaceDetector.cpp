#include<iostream>
#include<vector>
#include<stdexcept>

#include<opencv2/objdetect.hpp>


#include "FaceDetector.hpp"

FaceDetector::FaceDetector() {
    if(!classifier.load("haarcascade_frontalface_default.xml")){
        throw std::runtime_error("Could not load face detection model");
    }
}

std::vector<cv::Rect> FaceDetector::detect(const cv::Mat& image){
    std::vector<cv::Rect> faces;

    classifier.detectMultiScale(image, faces, 1.3, 5);

    return faces;
}