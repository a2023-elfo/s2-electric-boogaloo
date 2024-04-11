#ifndef PLANT_H
#define PLANT_H
#pragma once
#include "displayObject.h"
#include "bullet.h"
#include <vector>
#include <iostream>

class Plant:public DisplayObject
{
protected:
	int health = 1;

public:
	int getHealth();
	virtual bool checkHitBox(int, int);
	bool decreaseHealth(int);
	virtual char display();
	virtual void update();
};

#endif