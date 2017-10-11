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
		cout << x << ", " << y << endl;
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
		cout << "bordering size: " << bordering.size() << endl;
		vector<int> addable;
		if (x2 > 0) {
			if (cells[x2 - 1][y2].visited)
			{
				addable.push_back(1);
			}
		}
		if (x2 < maze::x - 2) {
			if (cells[x2 + 1][y2].visited)
			{
				addable.push_back(3);
			}
		}
		if (y2 > 0) {
			if (cells[x2][y2 - 1].visited)
			{
				addable.push_back(0);
			}
		}
		if (y2 < maze::y - 2) {
			if (cells[x2][y2 + 1].visited)
			{
				addable.push_back(2);
			}
		}
		
		int toConnect =addable[ rand() % addable.size()];
		cout << endl << toConnect << endl;

		cells[x2][y2].passages[toConnect] = true;

		if (toConnect==1)
		{
			cout << "left" << endl;
			cells[x2 - 1][y2].passages[3] = true;
		}
		if (toConnect==3)
		{
			cout << "right" << endl;

			cells[x2 + 1][y2].passages[1] = true;
		}
		if (toConnect==0)
		{
			cout << "top" << endl;

			cells[x2][y2 - 1].passages[2] = true;
		}
		if (toConnect==2)
		{
			cout << "bottom" << endl;

			cells[x2][y2 + 1].passages[0] = true;
		}
		justAdded.x = x2;
		justAdded.y = y2;
		cout << x2 << ", " << y2 << endl;
		cells[x2][y2].visited = true;

	} 
		while(bordering.size() != 0);
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
}

void maze::drawMaze()
{
	for (int i = 0; i < maze::x; i++) {
		for (int j = 0; j < maze::y; j++) {
			cells[i][j].drawCell(i, maze::x, j, maze::y);
		}
	}
}
