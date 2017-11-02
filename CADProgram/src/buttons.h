#pragma once
//this is to safeguard against included the same header file multiple times in a file

#include "common.h"
//inside of common.h is ofMain.h and buttons.h

//#pragma once means that this file has access to all of the functionionality of ofMain.h
//and nothing is is messed up by including buttons.h multiple times

class button {//a class called button
public:
	button(); 
	//some initializer called button()

	void draw();
	void checkClick(ofVec2f mousePos, ofVec2f& circleLocation);

	//checkClick takes in the position of the mouse as well as the position of the circle,
	//it needs the mouse position to check whether or not the button was clicked
	//it needs the circle position (passed by reference) so that it can modify them if the button was pressed

	void setButton(ofVec2f l, ofVec2f s, std::string t);
	//a setter function that sets the private variables: location, size and text
	//setter functions allow you to modify private members from outside of the class


	virtual void onClick(ofVec2f& circleLocation);
	//a virtual functions

	//virtual functions are functions that are redefined whenever a class inherits from button
	//this allows for different buttons that do different things when clicked
private:
	std::string text;
	ofVec2f location;
	ofVec2f size;
	//several member variables they are private because there is no reason for other parts of the program to access them

};

class upButton: public button {
//upButton inherits from button which means that it has a copy of all of button's members
public:
	upButton();
	//initializers cannot be inherited and need to be redeclared

	void onClick(ofVec2f& circleLocation);
	//onClick for the upButton is declared, this function will be called whenever the upButton is clicked
};

class downButton : public button {
	//downButton inherits from button which means that it has a copy of all of button's members
public:
	downButton();
	//initializers cannot be inherited and need to be redeclared

	void onClick(ofVec2f& circleLocation);
	//onClick for the downButton is declared, this function will be called whenever the downButton is clicked
};

class leftButton : public button {
	//leftButton inherits from button which means that it has a copy of all of button's members
public:
	leftButton();
	//initializers cannot be inherited and need to be redeclared

	void onClick(ofVec2f& circleLocation);
	//onClick for the leftButton is declared, this function will be called whenever the leftButton is clicked

};

class rightButton : public button {
	//leftButton inherits from button which means that it has a copy of all of button's members

public:
	rightButton();
	//initializers cannot be inherited and need to be redeclared

	void onClick(ofVec2f& circleLocation);
	//onClick for the rightButton is declared, this function will be called whenever the rightButton is clicked

};
