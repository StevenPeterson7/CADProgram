#include "player.h"
#include "ofMain.h"
#include <math.h>

player::player(int x, int y)
{
	player::x = x;
	player::y = y;

	player::centerAngle = 0;
}

void player::moveForward()
{
	int dx = 5 * cos(player::centerAngle);
	int dy = 5 * sin(player::centerAngle);
	player::x += dx;
	player::y += dy;
}

void player::moveBackward()
{
	int dx = 5 * cos(player::centerAngle);
	int dy = 5 * sin(player::centerAngle);
	player::x -= dx;
	player::y -= dy;
}

void player::moveLeft()
{
	int dx = 5 * cos(player::centerAngle-1.5708);
	int dy = 5 * sin(player::centerAngle-1.5708);
	player::x += dx;
	player::y += dy;
}

void player::moveRight()
{
	int dx = 5 * cos(player::centerAngle + 1.5708);
	int dy = 5 * sin(player::centerAngle + 1.5708);
	player::x += dx;
	player::y += dy;
}

void player::changeView()
{
}

void player::drawPlayer2d()
{
	ofDrawCircle(player::x, player::y, 5);
}

void player::drawPlayerView()
{
}
