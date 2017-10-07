#include "ofMain.h"
#include "ofApp.h"
#include <iostream>
#include <math.h>
#include "maze.h"

using namespace std;

//========================================================================
int main( ){
	cout << "Hello World";
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context'
	cell cell1;
	cell1.test();

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
