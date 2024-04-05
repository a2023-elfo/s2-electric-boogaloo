#ifndef GAMELOOP_H
#define GAMELOOP_H
#pragma once
#include "grid.h"
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include "grid.h"
#include "systemeArgent.h"
#include "healthBar.h"
#include "include/json.hpp"
#include "enums.h"
#include <qobject.h>

QT_BEGIN_NAMESPACE
namespace Ui {
	class Gameloop;
}
QT_END_NAMESPACE

class Gameloop : public QObject
{
	Q_OBJECT


public:
	void mainLoop();
	 std::vector<GameControls> readUserInput(nlohmann::json json_msg);
	bool checkPlayerInput(GameControls checkedInput, std::vector<GameControls>& inputVect);
	void spawnEnemy(int enemyPos, bool theRock);
	void spawnPeashooter(int health);
	void spawnPotato(int health);
	void activerTremblementDeTerre(int* charge, bool* usecharge);
	void afficherTremblementDeTerre(int* charge);
	void gameOver();
	void setupDirector();
	void inputUpdateDirector( std::vector<GameControls>& inputVect);
	void muonUpdateDirector();
	void generateEnemy();
	void generatePosition();
	int generateValue(int min, int max);

private:
	Grid arene;
	int charge;

	// Directpr values
	long long directorRandom = 1;
	int directorFunds = 0;

public slots:

signals:
	void gridUpdate(char grid[5][10]);
};

#endif