#ifndef GRID_H
#define GRID_H

#pragma once
#include <vector>
#include "enemy.h"
#include "potato.h"
#include "peaShooter.h"
#include "plant.h"
#include "bullet.h"
#include "player.h"
using namespace std;

class Grid
{
private:
	vector<Enemy> enemies;
	vector<Plant> plants;
	vector<Bullet> bullets;
	
public:
	Player playerShooter;
	void update();
	void display();
	void placePlant(Plant);
	Enemy* getEnemy(int index);
	vector<Enemy>& getEnemies();
	Plant* getPlant(int index);
	vector<Plant>& getPlants();

};

#endif