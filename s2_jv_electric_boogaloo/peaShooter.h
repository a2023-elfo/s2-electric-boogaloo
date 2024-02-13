#pragma once
#include "plant.h"

class peaShooter:plant
{
public:
	char display();
	void update();
	plant getX();
	plant getY();
	bullet shoot();
	peaShooter(int, int, int);
};

