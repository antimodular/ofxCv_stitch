#include "ofApp.h"

using namespace ofxCv;
using namespace cv;



int camWidth,camHeight;
int cnt;
bool didTranform;
bool allowToShowTransform;



//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 960;
    camHeight = 600;
    ofVideoGrabber temp_grabber;
    
    vector<ofVideoDevice> devices = temp_grabber.listDevices();
    
    
    int deviceId;
    vector<int> temp_validIDs;
    for(int i = 0; i < devices.size(); i++){
        string temp_deviceName = devices[i].deviceName;
        
        vector<string> splitName = ofSplitString(temp_deviceName, " ");
        cout << devices[i].id << ": " << devices[i].deviceName<<" : " << devices[i].hardwareName;
        if( devices[i].bAvailable && splitName[0] == "HD" && splitName[1] == "Pro"){
            // if( devices[i].bAvailable && splitName[0] == "FaceTime" && splitName[1] == "HD"){
            
            deviceId = i;
            temp_validIDs.push_back(i);
 
            
            cout << endl;
        }else{
            cout << " - unavailable " << endl;
        }
    }
    
    temp_grabber.close();
    
    
    cams[0].setDeviceID(temp_validIDs[0]);
    cams[0].initGrabber(camWidth, camHeight);
    
    cams[1].setDeviceID(temp_validIDs[1]);
    cams[1].initGrabber(camWidth, camHeight);

    
    //http://docs.opencv.org/modules/stitching/doc/high_level.html
    
    //http://stackoverflow.com/questions/16284126/opencv-stitcher-class-with-overlapping-stationary-cameras
    
    
    for(int i=0;i< 2;i++){
        imgs.push_back(Mat());
    }
    
    cnt = 0;
    didTranform = false;
    allowToShowTransform = false;
}

void ofApp::update() {
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    for(int i=0;i< 2;i++){
        cams[i].update();
        if(cams[i].isFrameNew()) {
            
            imgs[i] = (toCv(cams[i]));
            if(! imgs[i].data )                              // Check for invalid input
            {
                cout <<i<<  "Could not open or find the image" << std::endl ;
            }
            
            
            if(i==1){
                if(allowToShowTransform){
                    status = stitcher.composePanorama(imgs, pano );
                    if (status != cv::Stitcher::OK) {
                        cout << "Can't stitcher.composePanorama, error code = " << status << endl;
                        
                    }
                    
                }
            }
        }//end if(cams[i].isFrameNew())
    }//end for(int i=0;i< 2;i++){
    
    
    
    
    
    if(ofGetElapsedTimef() > 3 && didTranform == false){
        didTranform = true;
        bool try_use_gpu = false; //true; //
        //stitcher = Stitcher::createDefault(try_use_gpu);
        
        status = stitcher.estimateTransform( imgs );
        if (status != cv::Stitcher::OK) {
            cout << "Can't stitcher.estimateTransform, error code = " << status << endl;
            
        } else{
            allowToShowTransform = true;
        }
    }
    
}

void ofApp::draw() {
    ofSetColor(255);
    
    
    for(int i=0;i< 2;i++){
        cams[i].draw(i*480, 0,480,300);
        //   drawMat(imgs[i], i*camWidth, camHeight);
    }
    
    ofPushMatrix();
    ofScale(0.8,0.8);
    if(allowToShowTransform){
        ofSetColor(255);
        drawMat(pano, mouseX, mouseY);
    }
    ofPopMatrix();
    
    
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 20, 20);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'f') ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
