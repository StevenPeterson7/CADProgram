#include "common.h"
#include "drawingLitty.h"

void ScrollClass::setup() {
	ofAddListener(ofEvents().mouseScrolled, this, &ScrollClass::mouseMoved);
	ofAddListener(ofEvents().mousePressed, this, &ScrollClass::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &ScrollClass::mouseReleased);
	//std::cout << "a";
}

ScrollClass::~ScrollClass() {
	ofRemoveListener(ofEvents().mouseScrolled, this, &ScrollClass::mouseMoved);
	ofRemoveListener(ofEvents().mousePressed, this, &ScrollClass::mouseDragged);
	ofRemoveListener(ofEvents().mouseReleased, this, &ScrollClass::mouseReleased);
}

void ScrollClass::mouseDragged(ofMouseEventArgs &mouse) {
	ScrollClass::pressed = true;
}

void ScrollClass::mouseReleased(ofMouseEventArgs &mouse) {
	ScrollClass::pressed = false;
}

void ScrollClass::mouseMoved(ofMouseEventArgs &mouse) {
	static double scrollChange = 0;
	scrollChange += mouse.scrollY;
	if (fabs(scrollChange) > 0.0) {

		ScrollClass::scale *= scrollChange > 0.0 ? 1: 0.9;
		scrollChange = 0;
	}
	
	//cout << mouse.scrollY;
	cout << scrollChange << endl;
	cout << mouse.x << endl;


}

void drawAxis(double scale, int numAxisNum, ScrollClass scroll) {
	ofClear(100,0,0);
	ofPolyline XAxis;
	float i = 0;
	while (i < 2) {
		float x = ofGetWidth() * i;
		float y = ofGetHeight() / 2;
		XAxis.addVertex(ofVec2f(x, y));
		i++;
	}
	XAxis.close();
	XAxis.draw(); 
	ofPolyline YAxis;
	i = 0;
	while (i <= 2) {
		float x = ofGetWidth() / 2;
		float y = ofGetHeight() * i;
		YAxis.addVertex(ofVec2f(x, y));
		i++;
	}
	YAxis.close();
	YAxis.draw();
	i = 1;
	int axisLabel = scale / numAxisNum;
	/*while (i < numAxisNum) {
		float x = ofGetWidth() / 2 + 5;
		float y = ofGetHeight() / (2 * numAxisNum) * i;
		ofDrawBitmapString(scale - (axisLabel * i), x, y);
		ofDrawBitmapString(-1 * (scale - (axisLabel * i)), x, ofGetHeight() - y);
		x = ofGetWidth() / (2 * numAxisNum) * i;
		y = ofGetHeight() / 2 + 5;
		ofDrawBitmapString(-1 * (scale - (axisLabel * i)), x, y + 10);
		ofDrawBitmapString(scale - (axisLabel * i), ofGetWidth() - x, y + 10);
		i++;
	}*/
	//cout << "bitch";
	if (scroll.pressed == true) {
		if (scroll.prevMouse.x == 0) {
			scroll.prevMouse.x = 0;
			scroll.prevMouse.y = 0;
		}

	}
}