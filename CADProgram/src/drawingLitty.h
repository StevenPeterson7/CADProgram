#pragma once
#include "common.h"

class ScrollClass {
public:
	bool pressed = false;
	ofVec2f mousePos;
	ofVec2f prevMouse;
	double scale = 100.0;
	int numAxisNum = 10;
	void setup();
	~ScrollClass();
	void mouseMoved(ofMouseEventArgs &mouse);
	void mouseDragged(ofMouseEventArgs &mouse);
	void mouseReleased(ofMouseEventArgs &mouse);
};

void drawAxis(double, int, ScrollClass);
//void mouseScrolled2(int,int);