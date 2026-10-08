#include<iostream>
#include<stdexcept>

#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>

#include "FaceDetector.hpp"

int main(){
    cv::VideoCapture video(0);

    if(!video.isOpened()){
            return -1;
    }

    cv::Mat img;

    try {
        FaceDetector faceDetector;

        while(true){
            video.read(img);

            std::vector<cv::Rect> faces = faceDetector.detect(img);

            for(cv::Rect face : faces){
                cv::rectangle(img, face.tl(), face.br(), cv::Scalar(50, 50, 255), 3);
            }

            cv::imshow("Frame", img);
            int key = cv::waitKey(1);

            if(char(key) == 'q'){
                break;
            }
        }

    }catch(const std::runtime_error& e){
        std::cerr << e.what() << '\n';
    }
    
    cv::destroyAllWindows();
    return 0;
}