#ifndef DISPLAYOBJECT_H
#define DISPLAYOBJECT_H
#pragma once
#include <iostream>
using namespace std;

class displayObject
{
protected:
	int x = 0;
	int y = 0;
	int width = 1;
	int height = 1;
public:
	virtual char display();
	virtual void update();
	int getX();
	void setX(int);
	int getY();
	void setY(int);
	int getWidth();
	void setWidth(int);
	int getHeight();
	void setHeight(int);
};

#endif;