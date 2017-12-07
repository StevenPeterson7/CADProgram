#include <vector>
#include "player.h"
#include "ofMain.h"
#include <math.h>
#include "maze.h"

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

void player::moveForward(maze nMaze)
{
	int dx = 5 * cos(player::centerAngle);
	int dy = 5 * sin(player::centerAngle);
	if (inWall(ofVec2f(x, y), ofVec2f(x + dx, y + dy), nMaze)) {

	}
	else {
		player::x += dx;
		player::y += dy;
	}
}

void player::moveBackward(maze nMaze)
{
	int dx = 5 * cos(player::centerAngle);
	int dy = 5 * sin(player::centerAngle);
	if (inWall(ofVec2f(x, y), ofVec2f(x - dx, y - dy), nMaze)) {

	}
	else {
		player::x -= dx;
		player::y -= dy;
	}
}

void player::moveLeft(maze nMaze)
{
	int dx = 5 * cos(player::centerAngle-1.5708);
	int dy = 5 * sin(player::centerAngle-1.5708);
	if (inWall(ofVec2f(x, y), ofVec2f(x + dx, y + dy), nMaze)) {

	}
	else {
		player::x += dx;
		player::y += dy;
	}
}

void player::moveRight(maze nMaze)
{
	int dx = 5 * cos(player::centerAngle + 1.5708);
	int dy = 5 * sin(player::centerAngle + 1.5708);
	if (inWall(ofVec2f(x,y), ofVec2f(x+dx, y+dy), nMaze)) {

	}
	else {
		player::x += dx;
		player::y += dy;
	}
}

void player::changeView()
{
}

void player::castDemRays(maze nMaze) {
}

void player::drawPlayer2d()
{
	ofSetColor(ofColor(0, 0, 0));
	
	ofDrawCircle(player::x, player::y, 2);
	//player::arc.draw();
}

void player::drawPlayerView()
{
}

bool player::inWall(ofVec2f before, ofVec2f after, maze nMaze) {
	ofVec2f prevCell(floor(before.x / nMaze.cellWidth), floor(before.y / nMaze.cellHeight));
	ofVec2f currentCell(floor(after.x / nMaze.cellWidth), floor(after.y / nMaze.cellHeight));

	if (prevCell.x < currentCell.x) {
		if (!nMaze.cells[prevCell.x][prevCell.y].passages[3]) {
			return true;

		}
	}
	if (prevCell.x > currentCell.x) {
		if (!nMaze.cells[prevCell.x][prevCell.y].passages[1]) {
			return true;

		}
	}
	if (prevCell.y < currentCell.y) {
		if (!nMaze.cells[prevCell.x][prevCell.y].passages[2]) {
			return true;

		}
	}
	if (prevCell.y > currentCell.y) {
		if (!nMaze.cells[prevCell.x][prevCell.y].passages[0]) {
			return true;

		}
	}
	return false;
	
	

}