#pragma once
#include "plant.h"
class potato: public plant
{
public:
	char display();
	void update();
	potato(int, int, int);
protected:
	int health = 10;
};

