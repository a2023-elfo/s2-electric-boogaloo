#ifndef GAMELOOP_H
#define GAMELOOP_H
#pragma once
#include "grid.h"
#include <conio.h>
#include <cstdlib>
#include <Windows.h>


class gameloop
{
public:
	void readUserInput();
	void translateUserInput();
	//void spawnPlayer();
	void spawnEnemy(int);
	void spawnPeashooter();
	void spawnPotato();
	void tremblementDeTerre();
	void gameOver();
private:
	grid arene;

	
};

#endif