#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //music.load("click.wav");
    //music.load("1.wav");
    //music.load("bell.wav");
    music.load("church.wav");
    music.setVolume(0.8);
  music.setLoop(true);
  //  music.setSpeed(5);
 //   music.setPan(1.0);
    fftSmooth = new float [8192];
    for (int i=0; i < 8192; i++) {
        fftSmooth[i] = 0;
    }
    reactive = 64;
    
    gui.setup();
    gui.add(size.setup("size",1,1,8));
//    gui.add(color.setup("color", ofColor(255,255,255,255),
//                        ofColor(0,0,0,0),
//                       ofColor(255,255,255,255)));
//    gui.add(background.setup("background", ofVec3f(0,0,0),
//                             ofVec3f(0,0,0),
//                             ofVec3f(255,255,255)));
//    gui.add(color.setup("color",
//                         ofColor::white,
//                         ofColor(0),
//                         ofColor(0)));
    gui.add(btnClear.setup("clear"));
    
    fbo.allocate(width, height);
    fbo.begin();
    ofClear(255);
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //ofBackground(background->x, background->y, background->z);
    if(btnClear){
        fbo.begin();
        ofClear(255);
        fbo.end();
    }
    
    ofSoundUpdate();
    
    float * value = ofSoundGetSpectrum(reactive);
    for(int i=0; i < reactive; i++) {
        fftSmooth[i] *= 0.15f;
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::black);
    fbo.draw(0,0);
    ofNoFill();
    //ofDrawRectangle(0,0,width,height);
    gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'b') {
            color = ofColor(0,0,0);
    }
    if(key == 'w') {
        color = ofColor(255,255,255);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  //  mousex=x;
   // mousey=y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    fbo.begin();
    for(int i = 0; i < reactive; i++){
           ofNoFill();
        ofSetColor(color);
        ofSetLineWidth(size);
           ofDrawCircle(ofGetMouseX(), ofGetMouseY(), -(fftSmooth[i]*200));
//           size = -(fftSmooth[i]*200);
       }
    
//    ofSetColor(color);
//    polyline.addVertex(ofPoint(x,y));
//    polyline.draw();
   
    fbo.end();
    music.setSpeed( 0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
    music.setPan( ((float)(ofGetWidth() - x) / (float)ofGetWidth())*0.8f);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    fbo.begin();
//    polyline.clear();
//    fbo.end();
    
    if(button == 0) {
        music.play();
    }
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
