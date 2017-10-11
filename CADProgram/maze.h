#pragma once
#include <vector>
#include "cell.h"

class maze
{
public:
	maze(int w, int h);
	std::vector< std::vector <cell> > cells;
	void generateMaze();
	void drawMaze();
	
private:
	int x;
	int y;
};