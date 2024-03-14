#pragma once
#include "enemy.h"
#include "plant.h"
#include "peaShooter.h"
#include "potato.h"
class systemeArgent
{
private:
		int money;
public:
	systemeArgent();
	void killZombie();
	bool checkFundsPeaShooter();
	bool checkFundsPotato();
	void buyPeaShooter();
	void buyPotato();
	int checkMoney();
};