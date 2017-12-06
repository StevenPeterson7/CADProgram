#include "gui.h"
#include "common.h"


void display::draw()
{
	for (int i = 0; i < display::buttons.size(); i++) {
		buttons[i]->draw();
	}
	for (int i = 0; i < display::toolBars.size(); i++) {
		toolBars[i]->draw();
	}
//	graphS.draw();
}

void display::checkClick(double x, double y, userDraw& user)
{
	display::buttonClicked = false;
	for (int i = 0; i < display::buttons.size(); i++) {
		display::buttons[i]->checkClick(x, y, user);
		if (display::buttons[i]->clicked == true) {
			display::buttonClicked = true;
		}
	}
	for (int i = 0; i < display::toolBars.size(); i++) {
		display::toolBars[i]->checkClick(x, y, user);
		if (display::toolBars[i]->clicked == true) {
			display::buttonClicked = true;
		}
	}

}

void display::checkHover(double x, double y)
{
//	std::cout << "display" << endl;

	for (int i = 0; i < display::buttons.size(); i++) {
		display::buttons[i]->checkHover(x, y);
		
	}
	for (int i = 0; i < display::toolBars.size(); i++) {
		display::toolBars[i]->checkHover(x, y);
		
	}
}

toolBar::toolBar()
{
}

toolBar::toolBar(ofVec2f l, ofVec2f s, int n)
{
	size = s;
	location = l;
	double xSize = (s.x / n) - 5;
	std::cout << "xSize: " << xSize << endl;
	std::stringstream ss;
	for (int i = 0; i < n; i++) {
		ss << i;

		buttons.push_back(new button(ofVec2f(i*(xSize + 5), location.y), ofVec2f(xSize, s.y), "test"));
	}

}

void toolBar::setToolBar(ofVec2f l, ofVec2f s)
{
	size = s;
	location = l;
}

void toolBar::addButton(button& newButton)
{
	buttons.push_back(&newButton);

}

void toolBar::setButton(button& setButton)
{

	buttons[index] = &setButton;
	index++;
}

void toolBar::draw()
{
	double xPos = 5;
	
	ofSetColor(ofColor(0, 0, 0));
	for (int i = 0; i < buttons.size(); i++) {
		if (buttons[i]->size.y > size.y) {
			buttons[i]->setSize(ofVec2f(buttons[i]->size.x, size.y));
		}
		//buttons[i]->setLocation(ofVec2f(xPos, location.y));
		xPos += buttons[i]->size.x + 5;
		buttons[i]->draw();

	}
	ofSetColor(ofColor::fromHex(0xFFFFFF));

	ofDrawRectangle(location, size.x, size.y);
}

void toolBar::checkClick(double x, double y, userDraw & user)
{
	clicked = false;
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->checkClick(x, y, user);
		if (buttons[i]->clicked == true) {
			clicked = true;
		}
	}
}

void toolBar::checkHover(double x, double y)
{
	//std::cout << "toolbar" << endl;
	for (int i = 0; i < toolBar::buttons.size(); i++) {
		toolBar::buttons[i]->checkHover(x, y);

	}
}


display::display()
{
	//graphS = graph();
}
