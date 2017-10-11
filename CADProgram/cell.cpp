#include <iostream>
#include "cell.h"
#include "ofMain.h"
#include <vector>

cell::cell(int x1, int y1) {
	passages[0] = false;
	passages[1] = false;
	passages[2] = false;
	passages[3] = false;
	isBorder = false;
	visited = false;

	cell::x = x1;
	cell::y = y1;


}

void cell::test() {
	std::cout << "test";
}

void cell::drawCell(int xPos, int mazeWidth, int yPos, int mazeHeight) {
	int wallWidth = 1;
	double cellWidth = 1024 / mazeWidth;
	double cellHeight = 700 / mazeHeight;
	ofSetColor(255);
	ofDrawRectangle(cellWidth*xPos, cellHeight*yPos, cellWidth, cellHeight);
	ofSetColor(0);
	if (!passages[0]) {
		ofDrawRectangle(cellWidth*xPos, cellHeight*yPos, cellWidth, wallWidth);
	}
	if (!passages[1]) {
		ofDrawRectangle(cellWidth*xPos, cellHeight*yPos, wallWidth, cellHeight);
	}
	if (!passages[2]) {
		ofDrawRectangle(cellWidth*xPos, cellHeight*(yPos + 1) - wallWidth, cellWidth, wallWidth);
	}
	if (!passages[3]) {
		ofDrawRectangle(cellWidth*(xPos + 1) - wallWidth, cellHeight*yPos, wallWidth, cellHeight);
	}

};