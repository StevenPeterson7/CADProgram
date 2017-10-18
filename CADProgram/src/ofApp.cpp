#include "ofApp.h"
#include "common.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	ofEnableDepthTest();
	ofSetVerticalSync(true);

	camera.setPosition(ofVec3f(100, 100, 50));
	camera.lookAt(ofVec3f(0, 0, 0));

	diffuse.setShininess(20);
	diffuse.setAmbientColor(ofColor(255, 0, 0));
	diffuse.setDiffuseColor(ofColor(255, 0, 0));
	diffuse.setSpecularColor(ofColor(255, 255, 255));

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
	
	camera.begin();
	mainLight.enable();
	diffuse.begin();

	ofDrawBox(30);

	diffuse.end();
	mainLight.disable();
	camera.end();
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
	
	camera.orbit(x, y, sqrt(pow(camera.getPosition().x, 2) + pow(camera.getPosition().y, 2) + pow(camera.getPosition().z, 2)), ofVec3f(0, 0, 0));
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
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
