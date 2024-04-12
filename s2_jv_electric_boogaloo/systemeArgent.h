#pragma once
#include "enemy.h"
#include "plant.h"
#include "peaShooter.h"
#include "potato.h"
#include <QObject>
#include <QLabel>

class systemeArgent : public QObject
{
	Q_OBJECT
private:
		int money;
		QLabel* curentMoneyLabel;
public:
	systemeArgent();
	void killZombie();
	bool checkFundsPeaShooter();
	bool checkFundsPotato();
	void buyPeaShooter();
	void buyPotato();
	int checkMoney();
	void moreMoney(int moneyIn);
};