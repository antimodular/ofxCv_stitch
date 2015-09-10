#Panorama stitching via openCv

## Introduction
In this example we grab the video-feed of 2 usb webcams (Logitech c920) and stitch them together via openCV's (version 2) stitcher library.

We based our code of these great examples:
<http://docs.opencv.org/modules/stitching/doc/high_level.html>
<http://stackoverflow.com/questions/16284126/opencv-stitcher-class-with-overlapping-stationary-cameras>


# Dependencies
of_v0.9.0RC1_osx_release 

ofxOpenCV

ofxCv
https://github.com/kylemcdonald/ofxCv

In order for this addon to work with OF0.9.0 we had to make some edits.
The modified addon is included here.



# Operating systems

Has only been tested on osx 10.10 with OF 0.9.0

## Images
Screen shot:

![](https://raw.githubusercontent.com/antimodular/ofxCv_stitch/master/stitched.png)