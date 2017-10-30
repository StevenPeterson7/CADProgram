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

void button::draw()
{
	ofSetColor(ofColor::fromHex(0xFFFFFF));

	ofDrawRectangle(button::location, button::size.x, button::size.y);
	ofSetColor(ofColor(0, 0, 0));
	ofDrawBitmapString(button::text, button::location.x + 25, button::location.y + 25);
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
