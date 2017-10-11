#pragma once

class cell
{
public:
	cell(int x1, int y1);
	void test();
	bool passages[4];
	bool visited;
	bool isBorder;
	int x, y;
	void drawCell(int xPos, int mazeWidth, int yPos, int mazeHeight);
};