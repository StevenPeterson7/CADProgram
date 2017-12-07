#pragma once
#include <vector>
#include "cell.h"

class maze
{
public:
	maze(int w, int h);
	std::vector< std::vector <cell> > cells;
	std::vector< std::vector <bool> > path;
	std::vector< std::vector <bool> > wasHere;

	void generateMaze();
	void drawMaze();
	void solve();
	bool recursiveSolve(int xSolve, int ySolve);
	
private:
	int startX;
	int startY;
	int endX;
	int endY;
	int x;
	int y;
};