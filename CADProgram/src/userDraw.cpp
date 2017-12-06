#include "common.h"
#include "userDraw.h"

graph::graph()
{
	xMin = -10;
	yMin = -10;
	xMax = 10;
	yMax = 10;
	xScale = 1;
	yScale = 1;
	xAxisPoints[0] = ofVec2f(0, ofGetWindowHeight() / 2);
	xAxisPoints[1] = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight() / 2);
	yAxisPoints[0] = ofVec2f(ofGetWindowWidth() / 2, 0);
	yAxisPoints[1] = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight());

}

void graph::resizeX(double scalar)
{
	xMax *= scalar;
	xMin *= scalar;
}

void graph::resizeY(double scalar)
{
	yMax *= scalar;
	yMin *= scalar;
}

void graph::rescaleX(double scale)
{
	xScale = scale;
}
void graph::rescaley(double scale)
{
	yScale = scale;
}

void graph::draw()
{
	ofPolyline xAxis;
	ofPolyline yAxis;

	std::vector <ofPolyline> xScaleLines;
	std::vector <ofPolyline> yScaleLines;


	xAxis.addVertex(xAxisPoints[0]);
	xAxis.addVertex(xAxisPoints[1]);
	yAxis.addVertex(yAxisPoints[0]);
	yAxis.addVertex(yAxisPoints[1]);

	ofSetColor(ofColor(0, 0, 0));

	for (int i = 0; i < (xMax - xMin) / xScale; i++) {
		ofPolyline temp;
		temp.addVertex(ofGetWindowWidth() / ((xMax - xMin) / xScale)*i, (ofGetHeight() / 2) - 5);
		temp.addVertex(ofGetWindowWidth() / ((xMax - xMin) / xScale)*i, (ofGetHeight() / 2) + 5);
		//temp.draw();
		xScaleLines.push_back(temp);
		stringstream ss;
		ss << (xScale*i) + xMin;
		ofDrawBitmapString(ss.str(), ofVec2f(ofGetWindowWidth() / ((xMax - xMin) / xScale)*i, (ofGetHeight() / 2) - 15));

	}
	for (int i = 0; i < (yMax - yMin) / yScale; i++) {
		ofPolyline temp;
		temp.addVertex((ofGetWidth() / 2) - 5, ofGetWindowHeight() / ((yMax - yMin) / yScale)*i);
		temp.addVertex((ofGetWidth() / 2) + 5, ofGetWindowHeight() / ((yMax - yMin) / yScale)*i);
		//temp.draw();
		yScaleLines.push_back(temp);
		stringstream ss;
		ss << (yScale*((yMax - yMin) / yScale) - i) + yMin;
		ofDrawBitmapString(ss.str(), ofVec2f((ofGetWindowWidth() / 2) - 25, ofGetWindowHeight() / ((yMax - yMin) / yScale)*i));
	}

	xAxis.draw();
	yAxis.draw();

	for (int i = 0; i < xScaleLines.size(); i++) {
		xScaleLines[i].draw();
	}
	for (int i = 0; i < yScaleLines.size(); i++) {
		yScaleLines[i].draw();
	}
}
userDraw::userDraw()
{
	graphS = graph();
}

void userDraw::switchShape(int shape)
{
	shapeDrawing = shape;

}

void userDraw::drawShapes()
{
	graphS.draw();
	for (int i = 0; i < polygons.size(); i++) {
		ofPolyline poly;
		for (int j = 0; j < polygons[i].size(); j++){
			poly.addVertex(polygons[i][j]);
		}
		
		poly.close();
		poly.draw();

	}
	for (int i = 0; i < circles.size(); i++) {
		ofDrawCircle(circles[i][0], sqrt(pow(circles[i][1].x - circles[i][0].x, 2) + pow(circles[i][1].y - circles[i][0].y, 2)));
	}
	/*for (int i = 0; i < triangles.size(); i++) {
		ofPolyline tri;
		for (int j = 0; j < 3; j++) {
			tri.addVertex(triangles[i][j]);
		}
		tri.close();
		tri.draw();

*/	for (int i = 0; i < lines.size(); i++) {
		ofPolyline line;
		for (int j = 0; j < 2; j++) {
			line.addVertex(lines[i][j]);
		}
		line.draw();

	}
}

void userDraw::makeShape(int x, int y, bool clicked, int buttonClicked)
{
	/*
	0-polygon
	1-line
	2-circle
	*/
		switch (shapeDrawing) {
		case 0:
			if (drawing) {
				polygons[polygons.size() - 1][pointNum] = ofVec2f(x, y);

				if (clicked) {
					if (buttonClicked == 0) {
							std::cout << pointNum << endl;
							pointNum++;
							polygons[polygons.size() - 1].push_back(ofVec2f(x, y));
							
						
					}
					else {
						polygons[polygons.size() - 1].pop_back();
						polygons[polygons.size() - 1].push_back(polygons[polygons.size() - 1][0]);
						std::cout << "end shape" << endl;
						drawing = false;

					}
				}
				
			}
			else {
				pointNum = 0;
				std::vector <ofVec2f> points;
				for (int i = 0; i < 2; i++) {
					points.push_back(ofVec2f(x, y));


				}
				if (clicked && buttonClicked==0)
				{
					drawing = true;

					polygons.push_back(points);
					std::cout << pointNum << endl;

					pointNum++;
				}
			}

			break;
		case 1:
	
			if (drawing) {
				if (clicked) {
					drawing = false;
				}
				lines[lines.size() - 1][1] = ofVec2f(x, y);
			}
			else {
				
					std::vector <ofVec2f> points;
					points.push_back(ofVec2f(x, y));
					points.push_back(ofVec2f(x, y));
					if (clicked)
					{
						drawing = true;

						lines.push_back(points);
					}
			}
			break;
		case 2:
			if (drawing) {
				if (clicked) {
					drawing = false;
				}
				circles[circles.size() - 1][1] = ofVec2f(x, y);
			}
			else {

				std::vector <ofVec2f> points;
				points.push_back(ofVec2f(x, y));
				points.push_back(ofVec2f(x, y));
				if (clicked)
				{
					drawing = true;

					circles.push_back(points);
				}
			}
			break;
		case 3:
			break;
		}
	
	
}
