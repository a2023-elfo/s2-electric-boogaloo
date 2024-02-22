#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#pragma once
#include "plant.h"

class peaShooter: public plant
{
public:
	char display();
	void update();
	peaShooter(int, int, int);
protected:
	int health = 5;
};

#endif