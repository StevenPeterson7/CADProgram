#include "ofApp.h"
#include "common.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	ofEnableDepthTest();
	ofSetVerticalSync(true);

	camera.setPosition(ofVec3f(0, 0, cameraDistance));

	diffuse.setShininess(20);
	diffuse.setAmbientColor(ofColor(200, 200, 200));
	diffuse.setDiffuseColor(ofColor(200, 200, 200));
	diffuse.setSpecularColor(ofColor(230, 230, 230));

	mainLight.setPointLight();
	mainLight.setGlobalPosition(ofVec3f(0, 0, mainLightDistance));
	mainLight.orbit(mainLightOrbitOffset[0], mainLightOrbitOffset[1], mainLightDistance, ofVec3f(0, 0, 0));
	mainLight.setAmbientColor(ofColor(150, 150, 150));
	mainLight.setDiffuseColor(ofColor(255, 255, 255));
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
void ofApp::mouseMoved(int x, int y) {
	
	lastMousePosition.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	
	const float xPrime = lastOrbitPosition.x + x - lastMousePosition.x;
	const float yPrime = lastOrbitPosition.y + y - lastMousePosition.y;

	camera.orbit(xPrime, yPrime, cameraDistance, ofVec3f(0, 0, 0));
	mainLight.orbit(xPrime + mainLightOrbitOffset[0], yPrime + mainLightOrbitOffset[1], mainLightDistance, ofVec3f(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	
	lastOrbitPosition.set(lastOrbitPosition.x + x - lastMousePosition.x, lastOrbitPosition.y + y - lastMousePosition.y);
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
