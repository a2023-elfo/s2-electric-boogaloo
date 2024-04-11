#include "displayObject.h"


char DisplayObject::display() {
	return('X');
}

void DisplayObject::update() {
	std::cout << "update non overwriter\n";
}

int DisplayObject::getX() const
{
	return x;
}

void DisplayObject::setX(int input)
{ 
	if (input < 0) {
		x = 0;
	}
	else if (input > 4) {
		x = 4;
	}
	else {
		x = input;
	}
}

int DisplayObject::getY() const
{
	return y;
}

void DisplayObject::setY(int input)
{
	if (input < 0) {
		y = 0;
	}
	else if (input > 9) {
		y = 9;
	}
	else {
		y = input;
	}
}