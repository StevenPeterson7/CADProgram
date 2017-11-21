#pragma once
#include "common.h"

class toolBar {
public:
	std::vector <button*> buttons;
	ofVec2f size;
	int index = 0;
	ofVec2f location;
	toolBar();
	toolBar(ofVec2f l, ofVec2f s, int n);
	void setToolBar(ofVec2f l, ofVec2f s);
	void addButton(button& newButton);
	void setButton(button& setButton);

	void draw();
	void checkClick(double x, double y, userDraw& user);
	void checkHover(double x, double y);
	bool clicked;

};

class display {
public:
	display();
	std::vector  <toolBar*> toolBars;
	std::vector <button*> buttons;
	

	void draw();
	void checkClick(double x, double y, userDraw& user);
	void checkHover(double x, double y);
	bool buttonClicked;
};