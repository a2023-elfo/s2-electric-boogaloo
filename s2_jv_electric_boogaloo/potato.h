#ifndef POTATO_H
#define POTATO_H

#pragma once
#include "plant.h"
class potato: public plant
{
public:
	char display();
	void update();
	potato(int x, int y, int health = 10);
protected:
	int health = 10;
};

#endif