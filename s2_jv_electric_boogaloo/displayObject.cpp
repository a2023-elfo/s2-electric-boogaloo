#include "displayObject.h"


char displayObject::display() {
	return('X');
}

void displayObject::update() {
	std::cout << "update non overwriter\n";
}

int displayObject::getX()
{
	return x;
}

void displayObject::setX(int input)
{
	x = input;
}

int displayObject::getY()
{
	return y;
}

void displayObject::setY(int input)
{
	y = input;
}

int displayObject::getWidth()
{
	return width;
}

void displayObject::setWidth(int input)
{
	width = input;
}

int displayObject::getHeight()
{
	return height;
}

void displayObject::setHeight(int input)
{
	height = input;
}
