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
	bool checkHitBox(bullet& bang);
	bool decreaseHealth(int damage);
	char display();
	void update(vector<bullet>& bullets, int deplacement);
	enemy(int _health, int x);
	getHealth();
	//enemy();
};

#endif