#pragma once
#include "common.h"

class graph {
public:
	ofVec2f xAxisPoints[2];
	ofVec2f yAxisPoints[2];

	graph();
	int xScale;
	int yScale;

	double xMax;
	double xMin;
	double yMax;
	double yMin;

	void resizeX(double scalar);
	void resizeY(double scalar);

	void rescaleX(double scale);
	void rescaley(double scale);

	void draw();

};
class userDraw {
public:
	userDraw();
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
	graph graphS;
};