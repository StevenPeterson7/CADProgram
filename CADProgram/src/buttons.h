#pragma once
#include "common.h"
class button {
public:
	bool visible;
	std::string text;
	ofVec2f location;
	ofVec2f size;
	//button(ofVec2f location, ofVec2f size, std::string text);
	void setButton(ofVec2f location, ofVec2f size, std::string text);
	button(ofVec2f l, ofVec2f s, std::string t);
	button();
	void setSize(ofVec2f s);
	virtual void setLocation(ofVec2f l);
	void setText(std::string t);
	void setVisible(bool v);


	virtual void draw();
	virtual void checkClick(double x, double y, userDraw& user);
	virtual void onClick(userDraw& user);
	virtual void checkHover(double x, double y);
	virtual void expand();
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
	drawCircleButton(ofVec2f location, ofVec2f size, std::string text);
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

};
class dropDownButton : public button {
public:
	dropDownButton(ofVec2f location, ofVec2f size, std::string text, int n);
	std::vector<button*> dropDownList;
	bool expanded = false;
	void draw();
	void checkClick(double x, double y, userDraw& user);
	void setLocation(ofVec2f l);
	void onClick(userDraw &user);
	void checkHover(double x, double y);
	void expand();



};
