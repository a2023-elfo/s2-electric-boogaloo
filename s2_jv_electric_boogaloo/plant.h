#ifndef PLANT_H
#define PLANT_H
#pragma once
#include "displayObject.h"
#include "bullet.h"
#include "enemy.h"
class plant: public displayObject
{
protected:
	int health = 1;

public:
	int getHealth();
	bool checkHitBox(int, int);
	bool decreaseHealth(int);
	virtual char display();
	virtual void update();
};

#endif