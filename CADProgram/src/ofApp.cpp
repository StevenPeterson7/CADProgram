#include "ofApp.h"
#include <math.h>
vector<int> points;
bool sizingCircle = false;
//--------------------------------------------------------------
void ofApp::setup(){
	

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < points.size(); i += 7) {
		ofSetColor(ofColor(points[i + 2], points[i + 3], points[i + 4]));
		ofDrawCircle(points[i], points[i + 1], sqrt(pow(points[i + 5] - points[i], 2) + pow(points[i + 6] - points[i + 1], 2)));
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
	points.pop_back();
	points.pop_back();
	points.push_back(x);
	points.push_back(y);
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
	sizingCircle = true;
	points.push_back(x);
	points.push_back(y);

	cout << "pressed: " << x << ", " << y << endl;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	points.pop_back();
	points.pop_back();
	points.push_back(x);
	points.push_back(y);
	sizingCircle = false;
	cout << "released: " << x << ", " << y << endl;

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
