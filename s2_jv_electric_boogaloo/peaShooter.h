#pragma once
#include "plant.h"
class peaShooter:plant
{
public:
	char display();
	void update();
	bullet shoot();
	peaShooter(int, int, int);
};

