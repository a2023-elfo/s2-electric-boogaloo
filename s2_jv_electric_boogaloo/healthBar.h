#pragma once
#include "displayObject.h"

class HealthBar : public DisplayObject
{
private:
	int health = 10;
	int maxhealth = 10;
public:
	HealthBar(int baseHealth);
	void setHealth(int amount);
	int getHealth();
	int getMaxHealth();
	void setMaxHealth(int amount);
	int decreaseHealth(int amount);
	void increaseHealth(int amount);
	std::string displayBar();
};

