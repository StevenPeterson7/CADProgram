#pragma once
#include "common.h"



class display {
public:
	std::vector <drawLineButton> lbuttons;
	std::vector <drawPolyButton> pbuttons;
	std::vector <drawCircleButton> cbuttons;
	std::vector <clearButton> clearbuttons;

	std::vector <dropDownButton> dbuttons;

	void draw();
	void checkClick(double x, double y, userDraw& user);
	bool buttonClicked;
};

