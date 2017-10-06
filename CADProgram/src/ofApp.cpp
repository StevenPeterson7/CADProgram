#include "ofApp.h"
vector<int> points;
//--------------------------------------------------------------
void ofApp::setup(){
	

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < points.size(); i += 5) {
		ofSetColor(ofColor(points[i + 2], points[i + 3], points[i + 4]));
		ofDrawCircle(points[i], points[i + 1], 100);
		
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	points.push_back(x);
	points.push_back(y);
	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255;
	points.push_back(r);
	points.push_back(g);
	points.push_back(b);

	cout << r << ", " << g << ", " << b << endl;

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
