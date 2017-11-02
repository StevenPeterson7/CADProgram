//it is important to include "buttons.h" so that buttons.cpp can know what functions and methods it is defining
#include "buttons.h"
//we are relying on some of the functionality in ofMain.h
#include "ofMain.h"


button::button()
{
	//we can just leave the constructor empty for this example
}

void button::setButton(ofVec2f l, ofVec2f s, std::string t)
{
	//this is a setter function, all it does is set the classes' private members from inputs
	location = l;
	size = s;
	text = t;
}

void button::draw()
{
	//This sets the color of the button to white
	ofSetColor(ofColor::fromHex(0xFFFFFF));
	//draws a rectangle at the set location with the set size
	ofDrawRectangle(button::location, button::size.x, button::size.y);
	//sets the color of the text to black
	ofSetColor(ofColor(0, 0, 0));
	//writes the text inside the button
	ofDrawBitmapString(button::text, button::location.x + size.x/4, button::location.y + size.y/2);
}

void button::checkClick(ofVec2f mousePos, ofVec2f& circleLocation)
{

	if (mousePos.x > button::location.x && mousePos.x < button::location.x + button::size.x && mousePos.y > button::location.y && mousePos.y < button::location.y + button::size.y)
	{
		//if the mouse's position is within the bounds of the button, run the onClick code
		onClick(circleLocation);
	}
	
}

void button::onClick(ofVec2f& circleLocation)
{ 
	//because all of the buttons we are using inherit from this class and re-define this function, no definition is necessary	
}


upButton::upButton()
{
	//because we are using a setter function, this constructor can be let empty
}

void upButton::onClick(ofVec2f& circleLocation)
{
	if (circleLocation.y > 100) {
		//if the circle location is not at the upper limit of the screen, move the circle up 10
		circleLocation.y -= 10;
	}
}

downButton::downButton()
{
}

void downButton::onClick(ofVec2f& circleLocation)
{
	if (circleLocation.y < ofGetViewportHeight() - 100) {
		circleLocation.y += 10;
	}
}

leftButton::leftButton()
{
}

void leftButton::onClick(ofVec2f& circleLocation)
{
	if (circleLocation.x > 100) {
		circleLocation.x -= 10;
	}
}

rightButton::rightButton()
{
}

void rightButton::onClick(ofVec2f& circleLocation)
{
	if (circleLocation.x < ofGetViewportWidth() - 100) {

		circleLocation.x += 10;
	}
}
