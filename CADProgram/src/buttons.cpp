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

void button::draw()
{
	ofSetColor(backgroundColor);

	ofDrawRectangle(location, size.x, size.y);
	ofSetColor(ofColor(0, 0, 0));
//	std::cout << text;
	ofDrawBitmapString(text, location.x + 25, location.y + 25);
	ofSetColor(ofColor(0, 0, 0));
	ofDrawRectangle(location.x - 1, location.y - 1, size.x + 2, size.y + 2);
}

void button::checkClick(double x, double y, userDraw& user)
{
	button::clicked = false;

	if (x > button::location.x && x<button::location.x + button::size.x && y>button::location.y && y < button::location.y + button::size.y)
	{
		onClick(user);
		button::clicked = true;
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


	if (x >location.x && x<location.x + size.x && y>location.y && y < location.y + size.y)
	{
		backgroundColor = ofColor(200, 200, 200);
		
	}
	else {
		backgroundColor = ofColor(255, 255, 255);
	}

}



drawCircleButton::drawCircleButton(ofVec2f l, ofVec2f s, std::string t, int test):button(l, s, t)
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

dropDownButton::dropDownButton(ofVec2f l, ofVec2f s, std::string t):button(l, s, t)
{

}

void dropDownButton::onClick()
{
	dropDownButton::text = "dat boi";
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
