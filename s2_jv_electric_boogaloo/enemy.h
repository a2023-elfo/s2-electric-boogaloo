#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include "bullet.h"
#include "potato.h"
#include "peaShooter.h"
#include "displayObject.h"
#include <random>

class Enemy : public DisplayObject
{
protected:
	int health;

public:
	Enemy(int _health, int x);
	bool checkHitBox(Bullet& bang);
	bool decreaseHealth(int damage);
	char display();
	void update(vector<Bullet>& bullets, vector<Potato> potatoes, vector<PeaShooter> peaShooters);
	int getHealth();
	void setDeplacement(int mouvement);
private:
	int deplacement;
};

#endif