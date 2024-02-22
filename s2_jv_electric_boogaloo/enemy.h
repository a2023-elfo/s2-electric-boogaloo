#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include "bullet.h"
#include "displayObject.h"
#include <random>
class enemy : public displayObject
{
protected:
	int health = 5;

public:
	bool checkHitBox(bullet&);
	bool decreaseHealth(int);
	char display();
	void update(bullet&, int);
	enemy(int);
	enemy();
};

#endif