#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#pragma once
#include "plant.h"

class PeaShooter: public Plant
{
public:
	char display();
	virtual void update(std::vector<Bullet>& bullets, bool fire);
	Bullet* shoot();
	PeaShooter(int health, int x, int y);
};

#endif