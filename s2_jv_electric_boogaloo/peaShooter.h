#pragma once
#include "plant.h"

class peaShooter:public plant
{
public:
	char display();
	void update();
	bullet shoot();
	peaShooter(int, int, int);
protected:
	int health = 5;
};

