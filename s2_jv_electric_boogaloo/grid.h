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

class grid
{
private:
	vector<enemy> enemies;
	vector<plant> plants;
	vector<bullet> bullets;
	
public:
	player playerShooter;
	void update();
	void display();
	void placePlant(plant);
	enemy* getEnemy(int index);
	vector<enemy>& getEnemies();
	plant* getPlant(int index);
	vector<plant>& getPlants();

};

#endif