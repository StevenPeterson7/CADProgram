#include <iostream>
#include "maze.h"
#include "ofMain.h"
#include <vector>

cell::cell(){
	passages[0] = false;
	passages[1] = false;
	passages[2] = false;
	passages[3] = false;

	visited = false;


}

void cell::test() {
	std::cout << "test";
}

void cell::drawCell(int xPos, int mazeWidth, int yPos, int mazeHeight) {
	double cellWidth = 1024 / mazeWidth;
	double cellHeight = 768 / mazeHeight;
	ofSetColor(255);
	ofDrawRectangle(cellWidth*xPos, cellHeight*yPos, cellWidth, cellHeight);
	ofSetColor(0);
	if (!passages[0]) {
		ofDrawRectangle(cellWidth*xPos, cellHeight*yPos, cellWidth, 5);
		}
	if (!passages[1]) {
		ofDrawRectangle(cellWidth*xPos, cellHeight*yPos, 5, cellHeight);
	}
	if (!passages[2]) {
		ofDrawRectangle(cellWidth*xPos, cellHeight*(yPos + 1) - 5, cellWidth, 5);
	}
	if (!passages[3]) {
		ofDrawRectangle(cellWidth*(xPos+1)-5, cellHeight*yPos, 5, cellHeight);
	}
	
};

maze::maze(int w, int h)
{
	maze::x = w;
	maze::y = h;


}

void maze::generateMaze()
{
	int xloc = 0, yloc = 0;
	while (xloc < 10 && yloc < 10) {
		cout << endl << xloc << ", " << yloc;
		if (xloc < 9 && yloc % 2 == 0) {
			cells[xloc][yloc].passages[1] = true;
			cells[xloc][yloc].passages[3] = true;
			xloc++;
		}else if (xloc > 0 && yloc % 2 == 1) {
			cells[xloc][yloc].passages[1] = true;
			cells[xloc][yloc].passages[3] = true;
			xloc--;
		}
		else if (xloc == 9 && yloc %2==0) {
			cells[xloc][yloc].passages[2] = true;
			cells[xloc][yloc].passages[3] = true;
			yloc++;
		}
		else if (xloc == 0 && yloc%2==1) {
			cells[xloc][yloc].passages[0] = true;
			cells[xloc][yloc].passages[3] = true;
			yloc++;
		}
		else if (xloc == 0 && yloc % 2 == 0) {
			cells[xloc][yloc].passages[0] = true;
			cells[xloc][yloc].passages[1] = true;
			yloc++;
		}
		else if (xloc == 9 && yloc % 2 == 1) {
			cells[xloc][yloc].passages[3] = true;
			cells[xloc][yloc].passages[0] = true;
			yloc++;
		}
	}
}

void maze::drawMaze()
{
	for (int i = 0; i < maze::x; i++) {
		for (int j = 0; j < maze::y; j++) {
			cells[i][j].drawCell(i, maze::x, j, maze::y);
		}
	}
}
