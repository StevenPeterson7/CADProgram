#pragma once
#include "common.h"

class userDraw {
public:
	int shapeDrawing=0;
	int pointNum = 0;
	bool drawing=false;
	std::vector < std::vector<ofVec2f> > polygons;
	std::vector < std::vector<ofVec2f> > circles;
	//std::vector < std::vector<ofVec2f> > triangles;
	std::vector < std::vector<ofVec2f> > lines;
	void switchShape(int shape);
	void drawShapes();
	void makeShape(int x, int y, bool clicked, int buttonClicked);
};