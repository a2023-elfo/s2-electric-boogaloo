#pragma once
#include "displayObject.h"
class enemy:displayObject
{
protected:
	int health = 1;

public:
	bool checkHitBox();
	bool decreaseHealth(int);
	char display();
	void update();
	enemy(int);
	enemy();
};

