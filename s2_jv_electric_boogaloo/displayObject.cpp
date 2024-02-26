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
	// On va devoir mettre les bornes du grid ici, question d'empêcher
	// les objets d'aller out of bounds
	x = input;
}

int DisplayObject::getY()
{
	return y;
}

void DisplayObject::setY(int input)
{
	y = input;
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
