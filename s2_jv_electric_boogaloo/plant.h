#pragma once
#include "displayObject.h"
#include "bullet.h"
#include "enemy.h"
class plant
{
protected:
	int health = 1;

public:
	bool checkHitBox(int, int);
	bool decreaseHealth(int);
	virtual char display();
	virtual void update();
	virtual int getX();
	virtual int getY();
	virtual bullet shoot();
};

