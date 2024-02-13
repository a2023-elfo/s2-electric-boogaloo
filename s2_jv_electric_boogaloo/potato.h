#pragma once
#include "plant.h"
class potato
{
public:
	char display();
	void update();
	plant getX();
	plant getY();
	bullet shoot();
	potato(int, int, int);
};

