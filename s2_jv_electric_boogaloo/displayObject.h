#ifndef DISPLAYOBJECT_H
#define DISPLAYOBJECT_H
#pragma once
#include <iostream>
#include <vector>

class DisplayObject
{
protected:
	int x = 0;
	int y = 0;
	int width = 1;
	int height = 1;
	enum BulletType { friendlyFire, notFriendlyFire, meaniesFire };
public:
	virtual char display();
	virtual void update();
	int getX() const;
	void setX(int);
	virtual int getY() const;
	virtual void setY(int);
	int getWidth();
	void setWidth(int);
	int getHeight();
	void setHeight(int);
};

#endif;