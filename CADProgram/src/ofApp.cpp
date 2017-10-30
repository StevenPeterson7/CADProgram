#include "ofApp.h"
#include "common.h"
//--------------------------------------------------------------
ofPolyline line;
void ofApp::setup() {
	display.cbuttons.push_back(drawCircleButton(ofVec2f(0, 50), ofVec2f(100, 100),  "draw circles"));
	display.pbuttons.push_back(drawPolyButton(ofVec2f(0, 200), ofVec2f(100, 100), "draw polygon"));
	display.lbuttons.push_back(drawLineButton(ofVec2f(0, 350), ofVec2f(100, 100), "draw lines"));
	display.clearbuttons.push_back(clearButton(ofVec2f(0, 500), ofVec2f(100, 100), "clear"));
	//display.dbuttons.push_back(dropDownButton(ofVec2f(0, 650), ofVec2f(100, 100), "draw lines"));




	ofEnableDepthTest();
	ofSetVerticalSync(true);

	camera.setPosition(ofVec3f(100, 100, 100));
	camera.lookAt(ofVec3f(0, 0, 0));

	mainLight.setAmbientColor(ofColor(100, 100, 100));
	mainLight.setPointLight();
	mainLight.setOrientation(ofVec3f(45, 45, 45));
	mainLight.setGlobalPosition(ofVec3f(0, 100, 200));
	mainLight.setDiffuseColor(ofColor(200, 0, 0));
	mainLight.setSpecularColor(ofColor(255, 255, 255));
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

/*	camera.begin();
	mainLight.enable();

	ofSetColor(255, 0, 0);
	ofFill();
	ofDrawBox(30);

	mainLight.disable();
	camera.end();*/
	ofSetColor(ofColor(255, 255, 255));
	display.draw();
	user.drawShapes();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
	user.makeShape(x, y, false, 0);

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	
	user.makeShape(x, y, false, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (!user.drawing) {
		display.checkClick(x, y, user);
	}
	if (!display.buttonClicked) {
		user.makeShape(x, y, true, button);
	}

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
