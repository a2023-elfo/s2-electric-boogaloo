#ifndef GRID_H
#define GRID_H

#pragma once
#include <vector>
#include "enemy.h"
#include "potato.h"
#include "peaShooter.h"
#include "bullet.h"
#include "player.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <qobject.h>
#include <iostream>

class Grid
{
private:
	 std::vector<Enemy> enemies;
	 std::vector<PeaShooter> peaShooters;
	 std::vector<Potato> potatoes;
	 std::vector<Bullet> bullets;
	
public:
	Player playerShooter;
	void update();
	void display();
	Enemy* getEnemy(int index);
	 std::vector<Enemy>& getEnemies();
	 std::vector<PeaShooter>& getPeaShooters();
	PeaShooter* getPeaShooter(int index);
	 std::vector<Potato>& getPotatoes();
	Potato* getPotato(int index);
	Bullet* getBullet(int index);
	 std::vector<Bullet>& getBullets();
	void deleteEnemy(int id);
	void deletePotato(int id);
	void deletePeaShooter(int id);
	int getEnemyNumber();
	static const int GRID_X = 5;
	static const int GRID_Y = 10;
	char grille[GRID_X][GRID_Y];
	int nbEnemyKilled = 0;
	int getHealthPlayer();
};

#endif