#include "ofApp.h"
#include "common.h"
//--------------------------------------------------------------
void ofApp::setup() {
	//display = new display();
	display.buttons.push_back(new drawCircleButton(ofVec2f(0, 50), ofVec2f(100, 100),  "draw circles", 15));
	display.buttons.push_back(new drawPolyButton(ofVec2f(0, 200), ofVec2f(100, 100), "draw polygon"));
	display.buttons.push_back(new drawLineButton(ofVec2f(0, 350), ofVec2f(100, 100), "draw lines"));
	display.buttons.push_back(new clearButton(ofVec2f(0, 500), ofVec2f(100, 100), "clear"));
	display.toolBars.push_back(new toolBar(ofVec2f(0, 0), ofVec2f(1280, 50), 15));


	

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
	//if (!takingPic)
	//{
		display.draw();
	//}
	ofSetColor(ofColor(0, 0, 0));

	user.drawShapes();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 's') {
		takingPic = true;
		//ofApp::draw();
		//img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());0
		//img.save("screenshot.jpg", OF_IMAGE_QUALITY_BEST);
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == 's') {
		takingPic = false;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
	user.makeShape(x, y, false, 0);
	display.checkHover(x, y);

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
