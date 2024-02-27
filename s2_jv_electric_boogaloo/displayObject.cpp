#include "displayObject.h"


char DisplayObject::display() {
	return('X');
}

void DisplayObject::update() {
	std::cout << "update non overwriter\n";
}

int DisplayObject::getX()
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
	// On va devoir mettre les bornes du grid ici, question d'empêcher
	// les objets d'aller out of bounds
	else {
		x = input;
	}
}

int DisplayObject::getY()
{
	return y;
}

void DisplayObject::setY(int input)
{
	if (input < 0) {
		y = 0;
	}
	if (input > 9) {
		y = 9;
	}
	else {
	y = input;
	}
}

int DisplayObject::getWidth()
{
	return width;
}

void DisplayObject::setWidth(int input)
{
	width = input;
}

int DisplayObject::getHeight()
{
	return height;
}

void DisplayObject::setHeight(int input)
{
	height = input;
}
