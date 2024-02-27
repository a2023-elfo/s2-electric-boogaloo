#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#pragma once
#include "plant.h"

class PeaShooter: public Plant
{
public:
	char display();
	void update();
	Bullet* shoot();
	PeaShooter(int x, int y, int health = 5);
};

#endif