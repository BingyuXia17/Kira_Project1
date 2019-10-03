#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
   
    ofPolyline polyline;
    ofxPanel gui;
    ofxIntSlider size;
    ofxColorSlider color;
    ofxVec3Slider background;
    ofxButton btnClear;
   // int count;
   
    
    ofFbo fbo;
    int width = 1024;
    int height = 786;
    
    ofSoundPlayer music;
    float * fftSmooth;
    int reactive;
		
//    int mousex;
//    int mousey;
  //  int size;
};
