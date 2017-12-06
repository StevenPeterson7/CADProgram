#include "common.h"
#include "buttons.h"

/*button::button(ofVec2f location, ofVec2f size, std::string text)
{
	button::location = location;
	button::text = text;
	button::size = size;
}*/

void button::setButton(ofVec2f l, ofVec2f s, std::string t)
{
	button::location = l;
	button::text = t;
	button::size = s;
}

button::button(ofVec2f l, ofVec2f s, std::string t)
{
	location = l;
	size = s;
	text = t;
	visible = true;
	clicked = false;
	backgroundColor = ofColor(255, 255, 255);

}

button::button()
{
}

void button::setSize(ofVec2f s)
{
	size = s;
}

void button::setLocation(ofVec2f l)
{
	location = l;
}

void button::setText(std::string t)
{
	text = t;
}

void button::setVisible(bool v)
{
	visible = v;
}

void button::draw()
{
	if (visible) {
		ofSetColor(backgroundColor);

		ofDrawRectangle(location, size.x, size.y);
		ofSetColor(ofColor(0, 0, 0));
		//	std::cout << text;
		ofDrawBitmapString(text, location.x + 25, location.y + 25);
		ofSetColor(ofColor(0, 0, 0));
		ofDrawRectangle(location.x - 1, location.y - 1, size.x + 2, size.y + 2);
	}
}

void button::checkClick(double x, double y, userDraw& user)
{
	if (visible) {
		button::clicked = false;

		if (x > button::location.x && x<button::location.x + button::size.x && y>button::location.y && y < button::location.y + button::size.y)
		{
			onClick(user);
			button::clicked = true;
		}
	}
	
}

void button::onClick(userDraw& user)
{
	text = "new";
	//virtual function inherit from superclass
	//function pointers
}

void button::checkHover(double x, double y)
{

	if (visible) {
		if (x > location.x && x<location.x + size.x && y>location.y && y < location.y + size.y)
		{
			backgroundColor = ofColor(175, 175, 200);

		}
		else {
			backgroundColor = ofColor(255, 255, 255);
		}
	}

}

void button::expand()
{
}



drawCircleButton::drawCircleButton(ofVec2f l, ofVec2f s, std::string t):button(l, s, t)
{
	
}

void drawCircleButton::onClick(userDraw& user)
{
	user.switchShape(2);
}
drawLineButton::drawLineButton(ofVec2f l, ofVec2f s, std::string t):button(l, s, t)
{

}

void drawLineButton::onClick(userDraw& user)
{
	user.switchShape(1);
}

drawPolyButton::drawPolyButton(ofVec2f l, ofVec2f s, std::string t):button(l, s, t)
{

}

void drawPolyButton::onClick(userDraw& user)
{
	user.switchShape(0);
}

dropDownButton::dropDownButton(ofVec2f l, ofVec2f s, std::string t, int n):button(l, s, t)
{
	for (int i = 0; i < n; i++) {
		dropDownList.push_back(new button(ofVec2f(location.x, location.y +size.y+ i * 30), ofVec2f(size.x, 30), "test"));
	}
	expanded = false;

}

void dropDownButton::draw()
{
	if (visible)
	{
		ofSetColor(backgroundColor);

		ofDrawRectangle(location, size.x, size.y);
		ofSetColor(ofColor(0, 0, 0));
		//	std::cout << text;
		ofDrawBitmapString(text, location.x + 25, location.y + 25);
		ofSetColor(ofColor(0, 0, 0));
		ofDrawRectangle(location.x - 1, location.y - 1, size.x + 2, size.y + 2);
		if (expanded) {
			for (int i = 0; i < dropDownList.size(); i++) {
				dropDownList[i]->draw();
			}
		}
	}
	
}

void dropDownButton::checkClick(double x, double y, userDraw & user)
{
	if (visible) {

		clicked = false;

		if (x > location.x && x<location.x + size.x && y>location.y && y < location.y + size.y)
		{
			onClick(user);
			clicked = true;
		}
		if (expanded) {
			for (int i = 0; i < dropDownList.size(); i++) {
				dropDownList[i]->checkClick(x, y, user);
				if (dropDownList[i]->clicked) {
					clicked = true;
				}
			}
		}
	}
}

void dropDownButton::setLocation(ofVec2f l)
{
	location = l;
	for (int i = 0; i < dropDownList.size(); i++) {
		dropDownList[i]->setLocation(ofVec2f(location.x, location.y + size.y + i * 25));
	}
}

void dropDownButton::onClick(userDraw &user)
{
	expanded = !expanded;
}

void dropDownButton::checkHover(double x, double y)
{
	if (visible) {

		if (x > location.x && x<location.x + size.x && y>location.y && y < location.y + size.y)
		{
			backgroundColor = ofColor(175, 175, 200);

		}
		else {
			backgroundColor = ofColor(255, 255, 255);
		}
		if (expanded) {
			for (int i = 0; i < dropDownList.size(); i++) {
				if (x > dropDownList[i]->location.x && x<dropDownList[i]->location.x + dropDownList[i]->size.x && y>dropDownList[i]->location.y && y < dropDownList[i]->location.y + dropDownList[i]->size.y)
				{
					dropDownList[i]->backgroundColor = ofColor(175, 175, 200);

				}
				else {
					dropDownList[i]->backgroundColor = ofColor(255, 255, 255);
				}
			}
		}
	}
}

void dropDownButton::expand()
{
	expanded = true;
}

clearButton::clearButton(ofVec2f l, ofVec2f s, std::string t):button(l, s, t)
{

}
void clearButton::onClick(userDraw & user)
{

	user.circles.clear();
	user.polygons.clear();
	user.lines.clear();
}

zoomIn::zoomIn(ofVec2f l, ofVec2f s, std::string t):button(l,s,t)
{
}

void zoomIn::onClick(userDraw & user)
{
	std::cout << "zoom in" << endl;

	user.graphS.resizeX(0.91);
	user.graphS.resizeY(0.91);
}



zoomOut::zoomOut(ofVec2f l, ofVec2f s, std::string t):button(l,s,t)
{
}

void zoomOut::onClick(userDraw & user)
{
	std::cout << "zoom out" << endl;
	user.graphS.resizeX(1.1);
	user.graphS.resizeY(1.1);
}

enterText::enterText(ofVec2f l, ofVec2f s)
{
}

void enterText::draw()
{
}

void enterText::editText()
{
}

void enterText::submit()
{
}

