#include "common.h"
#include "userDraw.h"

void userDraw::switchShape(int shape)
{
	shapeDrawing = shape;

}

void userDraw::drawShapes()
{
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
