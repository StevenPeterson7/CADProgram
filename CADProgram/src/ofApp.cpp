#include "ofApp.h"
#include "common.h"
//--------------------------------------------------------------
void ofApp::setup() {
	lbutton.setButton(ofVec2f(100, 500), ofVec2f(50, 20), "left");
	ubutton.setButton(ofVec2f(150, 460), ofVec2f(50, 20), "up");
	rbutton.setButton(ofVec2f(200, 500), ofVec2f(50, 20), "right");
	dbutton.setButton(ofVec2f(150, 540), ofVec2f(50, 20), "down");

	circleLocation.x = 600;
	circleLocation.y = 300;
	/*
	lbutton = leftButton(ofVec2f(100, 500), ofVec2f(50, 20), "left");
	ubutton = upButton(ofVec2f(150, 460), ofVec2f(50, 20), "up");
	rbutton = rightButton(ofVec2f(200, 500), ofVec2f(50, 20), "right");
	dbutton = downButton(ofVec2f(150, 540), ofVec2f(50, 20), "down");
	*/
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofDrawCircle(circleLocation, 100);
	//draws a circle with the center at (x, y) with a radius of 100

	lbutton.draw();
	ubutton.draw();
	rbutton.draw();
	dbutton.draw();



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'w' && circleLocation.y > 100) {
		//will decrease y (moving the circle up) every time the w key 
		//is pressed as long as the circle is not at the top of the screen
		circleLocation.y -=10;
	}
	if (key == 's' && circleLocation.y < ofGetViewportHeight() - 100) {
		//will increase y (moving the circle down) every time the s key 
		//is pressed as long as the circle is not at the bottom of the screen
		circleLocation.y +=10;
	}
	if (key == 'a' &&  circleLocation.x > 100) {
		//will decrease x (moving the circle left) every time the a key 
		//is pressed as long as the circle is not at the far left of the screen
		circleLocation.x -=10;
	}
	if (key == 'd' && circleLocation.x < ofGetViewportWidth() - 100) {
		//will increase x (moving the circle right) every time the d key 
		//is pressed as long as the circle is not at the far right of the screen
		circleLocation.x +=10;
	}
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
	lbutton.checkClick(ofVec2f(x,y), circleLocation);
	ubutton.checkClick(ofVec2f(x, y), circleLocation);
	rbutton.checkClick(ofVec2f(x, y), circleLocation);
	dbutton.checkClick(ofVec2f(x, y), circleLocation);


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
