#pragma once
#include <iostream>
using namespace std;

class displayObject
{
protected:
	int x;
	int y;
	int width;
	int height;
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

