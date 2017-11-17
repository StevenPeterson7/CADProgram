#include "ofApp.h"
#include "common.h"
#include "drawingLitty.h"

ScrollClass scroll;

//--------------------------------------------------------------
void ofApp::setup() {
	
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	//ofAddListener(ofApp::mouseScrolled, this, &mouseScrolled);
	/**camera.setPosition(ofVec3f(100, 100, 100));
	camera.lookAt(ofVec3f(0, 0, 0));
	mainLight.setAmbientColor(ofColor(100, 100, 100));
	mainLight.setPointLight();
	mainLight.setOrientation(ofVec3f(45, 45, 45));
	mainLight.setGlobalPosition(ofVec3f(0, 100, 200));
	mainLight.setDiffuseColor(ofColor(200, 0, 0));
	mainLight.setSpecularColor(ofColor(255, 255, 255));**/

	
	scroll.setup();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	//camera.begin();
	//mainLight.enable();
	drawAxis(scroll.scale,scroll.numAxisNum,scroll);
	//mainLight.disable();
	//camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//cout <<;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) { 

}

void ofApp::mouseScrolled(int x, int y) {
	//cout << x;
}
