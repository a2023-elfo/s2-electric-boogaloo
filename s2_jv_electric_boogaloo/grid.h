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
	player playerShooter;
public:
	void update();
	void display();
	void placePlant(plant);
};

