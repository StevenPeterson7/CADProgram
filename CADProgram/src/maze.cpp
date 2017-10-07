#include <iostream>
#include "maze.h"

void cell :: test()
{
	std::cout << "test";
}
/*class cell {
public:
	bool[4] passages = { false, false, false, false };
	void drawCell(int xPos, int mazeWidth, int yPos, int mazeHeight) {
		double cellWidth = 1024 / mazeWidth;
		double cellHeight = 768 / mazeHeight;

		ofDrawRectangle(cellWidth*xPos, cellHeight*yPos, cellWidth, cellHeight);
	};
	
};*/