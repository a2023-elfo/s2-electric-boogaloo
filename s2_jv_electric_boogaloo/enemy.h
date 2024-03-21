#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include "bullet.h"
#include "displayObject.h"
#include <random>


#include <random>
class enemy : public displayObject
{
protected:
	int health = 5;

public:
	Enemy(int _health, int x, char appearance);
	bool checkHitBox(Bullet& bang);
	bool decreaseHealth(int damage);
	char display();
	void update(vector<Bullet>& bullets, vector<Potato> potatoes, vector<PeaShooter> peaShooters);
	int getHealth();
	void setDeplacement(int mouvement);
	char apparence;
private:
	int deplacement;
};

#endif