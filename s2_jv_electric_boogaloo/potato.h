#ifndef POTATO_H
#define POTATO_H

#pragma once
#include "plant.h"
class Potato: public Plant
{
public:
	char display();
	void update();
	Potato(int x, int y, int health = 10);
protected:
	int health = 10;
};

#endif