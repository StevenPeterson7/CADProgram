#pragma once

class cell
{
public:
	cell();
	void test();
	bool passages[4];
	bool visited;
	void drawCell(int xPos, int mazeWidth, int yPos, int mazeHeight);
};

class maze
{
public:
	maze(int w, int h);
	cell cells[150][150];
	void generateMaze();
	void drawMaze();
	
private:
	int x;
	int y;
};