#include <iostream>
#include <vector>
#include "maze.h"
#include "cell.h"
#include "ofMain.h"

maze::maze(int w, int h)
{
	cout << endl << "maze init";
	maze::x = w;
	maze::y = h;
	for (int i = 0; i < w; i++) {
		vector <cell> test;
		for (int j = 0; j < h; j++)
		{
			test.push_back(cell(i, j));
		}
		maze::cells.push_back(test);
	}
}

void maze::generateMaze()
{
	cout << endl << "maze gen";

	vector <cell> bordering;
	cell justAdded (0,0);
	bordering.push_back(cell(1,0));
	bordering.push_back(cell(0, 1));
	bool borderAdded = false;

	do {
		int x = justAdded.x;
		int y = justAdded.y;
		cells[x][y].visited = true;
		//cout << x << ", " << y << endl;
		if (x > 0) {
				if (!cells[x - 1][y].visited && !cells[x-1][y].isBorder) {
					bordering.push_back(cells[x - 1][y]);
					cells[x - 1][y].isBorder = true;
				}
		}

		borderAdded = false;
		if(x<(maze::x-1)) {
				if (!cells[x + 1][y].visited && !cells[x+1][y].isBorder) {
					bordering.push_back(cells[x + 1][y]);
					cells[x + 1][y].isBorder = true;
				}
		}
		borderAdded = false;
		if(y>0) {
			
				if (!cells[x][y - 1].visited && !cells[x][y-1].isBorder) {
					bordering.push_back(cells[x][y - 1]);
					cells[x][y - 1].isBorder = true;
				}
						
		}
		borderAdded = false;
		if (y < (maze::y - 1)) {

			if (!cells[x][y + 1].visited && !cells[x][y+1].isBorder) {
					bordering.push_back(cells[x][y + 1]);
					cells[x][y + 1].isBorder = true;
				}
		}
		
		int toAdd = rand() % bordering.size();
		int x2 = bordering[toAdd].x;
		int y2 = bordering[toAdd].y;
		bordering.erase(bordering.begin() + toAdd);
		//cout << "bordering size: " << bordering.size() << endl;
		vector<int> addable;

		if (x2 > 0) {
			if (cells[x2 - 1][y2].visited) {
				addable.push_back(1);
			}
		}
		if (x2 < maze::x - 2) {
			if (cells[x2 + 1][y2].visited) {
				addable.push_back(3);
			}
		}
		if (y2 > 0) {
			if (cells[x2][y2 - 1].visited) {
				addable.push_back(0);
			}
		}
		if (y2 < maze::y - 2) {
			if (cells[x2][y2 + 1].visited) {
				addable.push_back(2);
			}
		}
		int toConnect = 0;
		if (addable.size() != 0) {
			toConnect = addable[rand() % addable.size()];
		}
		//cout << endl << toConnect << endl;

		cells[x2][y2].passages[toConnect] = true;

		switch (toConnect) {
		case 0:
			cells[x2][y2 - 1].passages[2] = true;
			break;
		case 1:
			cells[x2 - 1][y2].passages[3] = true;
			break;
		case 2:
			cells[x2][y2 + 1].passages[0] = true;
			break;
		case 3:
			cells[x2 + 1][y2].passages[1] = true;
			break;
		}

		/*if (toConnect==1) {
			//cout << "left" << endl;
			cells[x2 - 1][y2].passages[3] = true;
		}
		if (toConnect==3) {
			//cout << "right" << endl;
			cells[x2 + 1][y2].passages[1] = true;
		}
		if (toConnect==0) {
			//cout << "top" << endl;
			cells[x2][y2 - 1].passages[2] = true;
		}
		if (toConnect==2) {
			//cout << "bottom" << endl;
			cells[x2][y2 + 1].passages[0] = true;
		*/
		justAdded.x = x2;
		justAdded.y = y2;
		//cout << x2 << ", " << y2 << endl;
		cells[x2][y2].visited = true;

	} while(bordering.size() != 0);
	/*int max = maze::x - 1;
	int min = 0;
	int xloc = 0, yloc = 0;
	while (xloc < maze::x && yloc < maze::y) {
		cout << endl << xloc << ", " << yloc;
		if (xloc !=max && xloc!=0 ) {
			cells[xloc][yloc].passages[1] = true;
			cells[xloc][yloc].passages[3] = true;
			if (yloc % 2 == 0) {
				xloc++;
			}else if ( yloc % 2 == 1) {
				xloc--;
			}
		}else if (xloc == max && yloc %2==0) {
			cells[xloc][yloc].passages[2] = true;
			cells[xloc][yloc].passages[1] = true;
			yloc++;
		}else if (xloc == 0 && yloc%2==1) {
			cells[xloc][yloc].passages[2] = true;
			cells[xloc][yloc].passages[3] = true;
			yloc++;
		}else if (xloc == 0 && yloc % 2 == 0) {
			cells[xloc][yloc].passages[0] = true;
			cells[xloc][yloc].passages[3] = true;
			xloc++;
		}else if (xloc == max && yloc % 2 == 1) {
			cells[xloc][yloc].passages[1] = true;
			cells[xloc][yloc].passages[0] = true;
			xloc--;
		}
	}*/

	for (int i = 0; i < cells.size(); i++) {
		std::vector <bool> temp;
		wasHere.push_back(temp);
		path.push_back(temp);
		for (int j = 0; j < cells[i].size(); j++) {
			wasHere[i].push_back(false);
			path[i].push_back(false);

		}
	}
}

void maze::drawMaze()
{
	double cellHeight = ofGetWindowHeight() / y;
	double cellWidth = ofGetWindowWidth() / y;


	for (int i = 0; i < maze::x; i++) {
		for (int j = 0; j < maze::y; j++) {
			
			
			cells[i][j].drawCell(i, maze::x, j, maze::y);
			if (maze::path[i][j]) {
				//std::cout << "test" << endl;
				ofSetColor(ofColor(255, 0, 0));
				ofDrawCircle(ofVec2f((i*cellWidth) + cellWidth / 2, (j*cellHeight) + cellHeight / 2), 1);
			}
		}
	}
}

void maze::solve()
{
	startX = 0;
	startY = 0;
	endX = cells.size()-1;
	endY = cells[0].size()-1;
	//endX = 25;
	//endY = 99;
	
	bool b = recursiveSolve(startX, startY);
	std::cout << "a solution is " << b << endl;
	std::cout << endl << endl << endl;

	for (int i = 0; i < path.size(); i++) {
		for (int j = 0; j < path[i].size(); j++) {
			if (path[j][i]) {
				std::cout << " 1";

			}
			else {
				std::cout << " 0";
			}
		}
		std::cout << endl;
	}
}

bool maze::recursiveSolve(int xSolve, int ySolve)
{
	int deadend = 0;

	if (xSolve == endX && ySolve == endY) {
		path[xSolve][ySolve] = true;
		return true;
	}


	if (wasHere[xSolve][ySolve]) {
		cout << wasHere[xSolve][ySolve];
		return false;
	}


	for (int i = 0; i < 4; i++) {
		if (cells[xSolve][ySolve].passages[i]) {
			deadend++;
		}
	}
	if (deadend < 2 && xSolve != startX && ySolve != startY) {
		return false;
	}

	wasHere[xSolve][ySolve] = true;


	if (cells[xSolve][ySolve].passages[1]) {
		if (recursiveSolve(xSolve - 1, ySolve)) {
			path[xSolve][ySolve] = true;

			return true;
		}
	}
	if (cells[xSolve][ySolve].passages[0]) {
		if (recursiveSolve(xSolve, ySolve - 1)) {
			path[xSolve][ySolve] = true;
			
			return true;
		}
	}
	if (cells[xSolve][ySolve].passages[3]) {
		if (recursiveSolve(xSolve + 1, ySolve)) {
			path[xSolve][ySolve] = true;

			return true;
		}
	}
	if (cells[xSolve][ySolve].passages[2]) {
		if (recursiveSolve(xSolve, ySolve + 1)) {
			path[xSolve][ySolve] = true;

			return true;
		}
	}


	return false;

}