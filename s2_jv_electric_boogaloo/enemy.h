#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include "bullet.h"
#include "displayObject.h"


#include <random>
class Enemy : public DisplayObject
{
protected:
	int health = 5;

public:
	bool checkHitBox(Bullet&);
	bool decreaseHealth(int damage);
	char display();
	void update(vector<Bullet>& bullets, int deplacement);
	Enemy(int _health, int x);
	int getHealth();
	//enemy();
};

#endif