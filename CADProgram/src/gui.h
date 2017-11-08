#pragma once
#include "common.h"

class toolBar {
public:
	std::vector <button*> buttons;
	ofVec2f size;
	ofVec2f location;
	toolBar();
	toolBar(ofVec2f l, ofVec2f s, int n);
	void setToolBar(ofVec2f l, ofVec2f s);
	void draw();
	void checkClick(double x, double y, userDraw& user);
	bool clicked;

};

class display {
public:
	std::vector  <toolBar*> toolBars;
	std::vector <button*> buttons;

	void draw();
	void checkClick(double x, double y, userDraw& user);
	bool buttonClicked;
};