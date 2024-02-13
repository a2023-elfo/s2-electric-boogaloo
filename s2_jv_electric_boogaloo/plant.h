#pragma once
#include "displayObject.h"
#include "bullet.h"
#include "enemy.h"
class plant :public displayObject
{
protected:
	int health = 1;

public:
	bool checkHitBox(int, int);
	bool decreaseHealth(int);
	virtual char display();
	virtual void update();
	virtual bullet shoot();
};

