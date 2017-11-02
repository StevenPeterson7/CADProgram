#pragma once
//this is to safeguard against included the same header file multiple times in a file

#include "common.h"
//this is a header file that was created in order to simplify the libraries that we are including

class ofApp: public ofBaseApp {

public:
	//this is where all of the apps functionality is included
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

private:
	// this is where you can include custom members that you might need for your program
	ofVec2f circleLocation;
	leftButton lbutton;
	upButton ubutton;
	rightButton rbutton;
	downButton dbutton;


};