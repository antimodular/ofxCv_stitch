#include "ofApp.h"

using namespace ofxCv;
using namespace cv;




void ofApp::setup() {

//http://docs.opencv.org/modules/stitching/doc/high_level.html
    
    ofDirectory dir;
    dir.listDir("");
    
      for (int i =0; i< dir.numFiles() && i<2; i++) {
   // for (int i =2; i< dir.numFiles(); i++) {
          ofFile f = dir.getFile(i);
          string filePath = f.getAbsolutePath();
        
          ofLog()<<i<<" filePath "<<filePath;

          ofImage temp_img;
          temp_img.loadImage(dir.getFile(i));
          temp_img.setImageType(OF_IMAGE_COLOR);
          img2.push_back(temp_img);
     
          
           imgArray[i] = Mat(333,500,CV_8UC3);
        imgArray[i] = toCv(temp_img);
          
          imgArray[i] = imread(ofToDataPath(dir.getName(i)), CV_LOAD_IMAGE_COLOR);
          imgs.push_back(imread(ofToDataPath(dir.getName(i)), CV_LOAD_IMAGE_COLOR));
          
          if(! imgs[i].data )                              // Check for invalid input
          {
              cout <<  "A Could not open or find the image" << std::endl ;
          }
          
          if(! imgArray[i].data )                              // Check for invalid input
          {
              cout <<  "Could not open or find the image" << std::endl ;
          }
          
          //imgs[i] = image;
      }
    
 
    ofLog()<<"imgs.size "<<imgs.size();

    
    
}

void ofApp::update() {
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

}

void ofApp::draw() {
    ofSetColor(255);

    
    bool try_use_gpu = false; //true; //
    Stitcher stitcher = Stitcher::createDefault(try_use_gpu);
    Stitcher::Status status = stitcher.stitch(imgs, pano);

    if (status != cv::Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << status << endl;
        
    }

    
    for(int i=0;i< 2;i++){
        drawMat(imgs[i], i*500, 0);
      //     drawMat(imgArray[i], i*500, 0);
      //  img2[i].draw(i*500, 250);
    }
     ofSetColor(255);
     drawMat(pano, 0, 400);
    //drawMat(image, 0, 400,400,400);
    //img2.draw(400,0);
}
