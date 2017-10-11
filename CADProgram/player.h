#pragma once

class player
{
public:
	double x;
	double y;
	const double viewAngle = 1.0472;
	double centerAngle;
	player(int x, int y);

	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();

	void changeView();
	
	void drawPlayer2d();

	void drawPlayerView();
};