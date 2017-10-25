#pragma once
#include "common.h"

class button {
public:
	std::string text;
	ofVec2f location;
	ofVec2f size;
	button(ofVec2f location, ofVec2f size, std::string text);
	void setButton(ofVec2f location, ofVec2f size, std::string text);
	void draw();
	void checkClick(double x,double y);
	void onClick();
	bool clicked;

};

class display {
public:
	std::vector <button> buttons;
	void draw();
	void checkClick(double x, double y);
	bool buttonClicked;
};
