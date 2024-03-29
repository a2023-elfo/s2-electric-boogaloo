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
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

class Grid
{
private:
	vector<Enemy> enemies;
	vector<Plant> plants;
	vector<PeaShooter> peaShooters;
	vector<Potato> potatoes;
	vector<Bullet> bullets;
	
public:
	Player playerShooter;
	void update();
	void display();
	Enemy* getEnemy(int index);
	vector<Enemy>& getEnemies();
	vector<PeaShooter>& getPeaShooters();
	PeaShooter* getPeaShooter(int index);
	vector<Potato>& getPotatoes();
	Potato* getPotato(int index);
	Plant* getPlant(int index);
	vector<Plant>& getPlants();
	Bullet* getBullet(int index);
	vector<Bullet>& getBullets();
	void deleteEnemy(int id);
	void deletePotato(int id);
	void deletePeaShooter(int id);
	int getEnemyNumber();
	static const int GRID_X = 5;
	static const int GRID_Y = 10;
	char grille[GRID_X][GRID_Y];
	int nbEnemyKilled = 0;
};

#endif