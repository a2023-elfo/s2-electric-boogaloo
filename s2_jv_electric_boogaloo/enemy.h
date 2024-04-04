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
	Enemy(int _health, int x, char appearance);
	bool checkHitBox(Bullet& bang);
	bool decreaseHealth(int damage);
	char display();
	void update(std::vector<Bullet>& bullets, std::vector<Potato> potatoes, std::vector<PeaShooter> peaShooters, std::vector<Enemy>& enemies);
	int getHealth();
	void setDeplacement(int mouvement);
private:
	int deplacement;
	char apparence;
};

#endif