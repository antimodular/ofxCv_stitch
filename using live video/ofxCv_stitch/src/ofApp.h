#pragma once

#include "ofMain.h"

#include "ofxCv.h"
#include "../../../addons/ofxOpenCv/libs/opencv/include/opencv2/stitching/stitcher.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofVideoGrabber cams[2];
    
    vector<cv::Mat> imgs;
    cv::Mat imgArray[2];
    
    vector<ofImage> img2;
    
    cv::Mat pano;
    
    cv::Stitcher stitcher = cv::Stitcher::createDefault(false); //true == use gpu
    cv::Stitcher::Status status;
};
