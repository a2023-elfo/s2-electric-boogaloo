#ifndef POTATO_H
#define POTATO_H

#pragma once
#include "plant.h"
class Potato: public Plant
{
public:
	char display();
	void update();
	Potato(int health, int x, int y);
	bool checkHitBox(int x, int y);
	bool decreaseHealth(int damage);
	int getHealth() const;
protected:
	int health;
};

#endif