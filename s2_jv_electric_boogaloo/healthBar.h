#pragma once
#include "displayObject.h"

class healthBar : public DisplayObject
{
private:
	int health = 5;
	int maxhealth = 5;
public:
	healthBar(int baseHealth);
	void setHealth(int amount);
	int getHealth();
	int getMaxHealth();
	void setMaxHealth(int amount);
	int decreaseHealth(int amount);
	void increaseHealth(int amount);
	string displayBar();
};

