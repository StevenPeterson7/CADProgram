#include <vector>
#include "player.h"
#include "ofMain.h"
#include <math.h>

player::player(int x, int y)
{
	player::x = x;
	player::y = y;

	player::centerAngle = 0;
	player::radius = 100;
	player::arc.arc(player::x, player::y, player::radius, player::radius, player::centerAngle-(player::viewAngle/2), player::centerAngle + (player::viewAngle / 2));

}

void player::changeRadius()
{
	player::radius++;
	player::arc.arc(player::x, player::y, player::radius, player::radius, player::centerAngle - (player::viewAngle / 2), player::centerAngle + (player::viewAngle / 2));

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

void player::castDemRays() {
}

void player::drawPlayer2d()
{
	
	ofDrawCircle(player::x, player::y, 2);
	player::arc.draw();
}

void player::drawPlayerView()
{
}