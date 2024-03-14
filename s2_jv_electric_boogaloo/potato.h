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
protected:
	int health = 10;
};

#endif