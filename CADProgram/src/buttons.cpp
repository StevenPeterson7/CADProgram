#include "common.h"
#include "buttons.h"

/*button::button(ofVec2f location, ofVec2f size, std::string text)
{
	button::location = location;
	button::text = text;
	button::size = size;
}*/

void button::setButton(ofVec2f location, ofVec2f size, std::string text)
{
	button::location = location;
	button::text = text;
	button::size = size;
}

button::button(ofVec2f l, ofVec2f s, std::string t)
{
	location = l;
	size = s;
	text = t;


}

button::button()
{
	text = "test";
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
	std::cout << text << endl;

	ofSetColor(ofColor::fromHex(0xFFFFFF));

	ofDrawRectangle(button::location, button::size.x, button::size.y);
	ofSetColor(ofColor(0, 0, 0));
	ofDrawBitmapString(button::text, button::location.x + 25, button::location.y + 25);
	ofSetColor(ofColor::fromHex(0x000000));
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

drawCircleButton::drawCircleButton(ofVec2f location, ofVec2f size, std::string text)
{
	drawCircleButton::location = location;
	drawCircleButton::size = size;
	drawCircleButton::text = text;
}

void drawCircleButton::onClick(userDraw& user)
{
	user.switchShape(2);
}
drawLineButton::drawLineButton(ofVec2f location, ofVec2f size, std::string text)
{
	drawLineButton::location = location;
	drawLineButton::size = size;
	drawLineButton::text = text;
}

void drawLineButton::onClick(userDraw& user)
{
	user.switchShape(1);
}

drawPolyButton::drawPolyButton(ofVec2f location, ofVec2f size, std::string text)
{
	drawPolyButton::location = location;
	drawPolyButton::size = size;
	drawPolyButton::text = text;
}

void drawPolyButton::onClick(userDraw& user)
{
	user.switchShape(0);
}

dropDownButton::dropDownButton(ofVec2f location, ofVec2f size, std::string text)
{
	dropDownButton::location = location;
	dropDownButton::size = size;
	dropDownButton::text = text;
}

void dropDownButton::onClick()
{
	dropDownButton::text = "dat boi";
}

clearButton::clearButton(ofVec2f location, ofVec2f size, std::string text)
{
	clearButton::location = location;
	clearButton::size = size;
	clearButton::text = text;

}

void clearButton::onClick(userDraw & user)
{
	user.circles.clear();
	user.polygons.clear();
	user.lines.clear();
}
