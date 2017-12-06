/*#include "common.h"
#include "ofApp.h"

int main() {
	
	ofSetupOpenGL(1280,700,OF_WINDOW);
	ofRunApp(new ofApp());
}*/
#include<iostream>


using namespace std;

void RectangleMaker(int, int, string);

int main() {
	int height = 0;
	int width = 0;
	string symbol;
	while (width != -1) {
		cout << "what is the width" << endl;
		cin >> width;
		if (width == -1) {
			break;
		}
		cout << "what is the height" << endl;
		cin >> height;

		cout << "what symbol (@,$,& etc...)" << endl;
		cin >> symbol;
		cout << " " << endl;
		RectangleMaker(height, width, symbol);
	}




}

void RectangleMaker(int height, int width, string symbol) {
	int counter2 = height;
	int counterWidth = width;
	while (height > 0) {

		//if(height == counter2 or height == 0){

		//  height--;
		//}
		if (height == 0) {

			height--;
		}
		if (height != counter2 and height != 0) {

			height--;
		}
		while (width >= 0) {
			if (width == counterWidth or height == counter2) {

				cout << symbol;
				width--;
			}

			if (width == 0 or width == counterWidth - 1 or height == 0 or height == counter2 - 1) {
				cout << symbol;
				width--;
			}

			if (width != counterWidth or width != 0 or height != counter2 or height != 0) {

				cout << " ";
				width--;
			}


		}
		cout << endl;
		width = counterWidth;

	}

}
