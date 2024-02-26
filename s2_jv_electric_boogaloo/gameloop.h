#ifndef GAMELOOP_H
#define GAMELOOP_H
#pragma once
#include "grid.h"
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include "grid.h"

class gameloop
{
public:
	void readUserInput();
	void translateUserInput();
	//void spawnPlayer();
	void spawnEnemy(int enemyPos, bool theRock);
	void spawnPeashooter(int health);
	void spawnPotato(int health);
	void tremblementDeTerre();
	void gameOver();
private:
	grid arene;

	
};

#endif