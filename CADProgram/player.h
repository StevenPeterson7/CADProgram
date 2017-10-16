#pragma once
#include <vector>
#include "ofMain.h"

class player
{
public:
	double x;
	double y;
	const double viewAngle = 60;
	double centerAngle;
	player(int x, int y);

	std::vector <ofVec2f> points;
	ofPath arc;
	double radius;

	void changeRadius();

	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();

	void changeView();

	void castDemRays();
	
	void drawPlayer2d();

	void drawPlayerView();
};