#pragma once

#include "ofMain.h"
#include "ofxCv.h"

//#include "opencv2/stitching/stitcher.cpp"

#include "../../../addons/ofxOpenCV2461/libs/opencv/include/opencv2/stitching/stitcher.hpp"


class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    
    vector<cv::Mat> imgs;
    cv::Mat imgArray[2];
    
    vector<ofImage> img2;
    cv::Mat pano;
    

    
};
