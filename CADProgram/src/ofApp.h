#pragma once

#include "common.h"

class ofApp: public ofBaseApp {

public:
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
	ofVec2f lastMousePosition;
	ofVec2f lastOrbitPosition;

	ofCamera camera;
	ofLight mainLight;
	ofMaterial diffuse;

	float cameraDistance = 100;
	const float mainLightDistance = 720;
	const float mainLightOrbitOffset[2] = { -50, -50 };
};