#include "gui.h"
#include "common.h"


button::button(ofVec2f location, ofVec2f size, std::string text)
{
	button::location = location;
	button::text = text;
	button::size = size;
}

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

void button::checkClick(double x, double y)
{
	button::clicked = false;

	if (x > button::location.x && x<button::location.x + button::size.x && y>button::location.y && y < button::location.y + button::size.y)
	{
		button::onClick();
		button::clicked = true;
	}
	else {
		button::text = "you missed me";
	}
}

void button::onClick()
{
	button::text = "you clicked me";
}

void display::draw()
{
	for (int i = 0; i < display::buttons.size(); i++) {
		buttons[i].draw();
	}
}

void display::checkClick(double x, double y)
{
	display::buttonClicked = false;
	for (int i = 0; i < display::buttons.size(); i++) {
		display::buttons[i].checkClick(x, y);
		if (display::buttons[i].clicked == true) {
			display::buttonClicked = true;
		}
	}
}

