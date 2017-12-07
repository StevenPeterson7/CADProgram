#pragma once
#include <vector>
#include "ofMain.h"
#include "maze.h"

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
	bool inWall(ofVec2f before, ofVec2f after, maze nMaze);

	void changeRadius();

	void moveForward(maze nMaze);
	void moveBackward(maze nMaze);
	void moveLeft(maze nMaze);
	void moveRight(maze nMaze);

	void changeView();

	void castDemRays(maze nMaze);
	
	void drawPlayer2d();

	void drawPlayerView();
};