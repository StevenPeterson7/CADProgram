#pragma once
#include "common.h"
class button {
public:
	std::string text;
	ofVec2f location;
	ofVec2f size;
	//button(ofVec2f location, ofVec2f size, std::string text);
	void setButton(ofVec2f location, ofVec2f size, std::string text);
	button(ofVec2f l, ofVec2f s, std::string t);
	button();
	void setSize(ofVec2f s);
	void setLocation(ofVec2f l);
	void draw();
	void checkClick(double x, double y, userDraw& user);
	virtual void onClick(userDraw& user);
	void checkHover(double x, double y);
	ofColor backgroundColor;
	
	bool clicked;

};

class drawLineButton: public button {
public:
	drawLineButton(ofVec2f location, ofVec2f size, std::string text);
	void onClick(userDraw& user);


};
class drawCircleButton : public button {
public:
	drawCircleButton(ofVec2f location, ofVec2f size, std::string text, int test);
	void onClick(userDraw& user);


};
class drawPolyButton : public button {
public:
	drawPolyButton(ofVec2f location, ofVec2f size, std::string text);
	void onClick(userDraw& user);


};
class clearButton : public button {
public:
	clearButton(ofVec2f location, ofVec2f size, std::string text);
	void onClick(userDraw& user);
	int test=5;

};
class dropDownButton : public button {
public:
	dropDownButton(ofVec2f location, ofVec2f size, std::string text);
	void onClick();


};
