#ifndef GAMELOOP_H
#define GAMELOOP_H
#pragma once
#include "grid.h"
#include <conio.h>

#include <Windows.h>


class gameloop
{
public:
	void readUserInput();
	void translateUserInput();
	void spawnPlayer();
	void spawnEnemy();
	void spawnPeashooter();
	void spawnPotato();
	void tremblementDeTerre();
	player joueur;
};

#endif