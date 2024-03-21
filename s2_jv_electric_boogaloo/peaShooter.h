#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#pragma once
#include "plant.h"

class PeaShooter: public Plant
{
public:
	bool checkHitBox(int x, int y);
	bool decreaseHealth(int damage);
	int getHealth();
	char display();
	virtual void update(std::vector<Bullet>& bullets, bool fire);
	Bullet* shoot();
	PeaShooter(int health, int x, int y);
protected:
	int health;
};

#endif