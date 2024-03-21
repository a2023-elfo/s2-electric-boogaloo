#ifndef GAMELOOP_H
#define GAMELOOP_H
#pragma once
#include "grid.h"
#include <conio.h>

#include <Windows.h>



class Gameloop
{
public:
	void mainLoop();
	vector<GameControls> readUserInput(nlohmann::json json_msg);
	bool checkPlayerInput(GameControls checkedInput, vector<GameControls>& inputVect);
	
	void spawnPeashooter(int health);
	void spawnPotato(int health);
	void tremblementDeTerre(int charge);
	void gameOver();
	void setupDirector();
	void inputUpdateDirector(vector<GameControls>& inputVect);
	void muonUpdateDirector();
	void generateEnemy();
	void generatePosition();
	int generateValue(int min, int max);
	

private:
	Grid arene;
	int charge;
	int nbEnemyKilled = 0;

	// Directpr values
	long long directorRandom = 1;
	int directorFunds = 0;
};

#endif