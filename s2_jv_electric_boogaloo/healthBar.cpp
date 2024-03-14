#include "healthBar.h"

healthBar::healthBar(int baseHealth)
{
	if (baseHealth > 0) {
		this->health = baseHealth;
	}
}

void healthBar::setHealth(int amount)
{
	if (amount > 0) {
		this->health = amount;
	}
}

int healthBar::getHealth()
{
	return health;
}

int healthBar::getMaxHealth()
{
	return maxhealth;
}

void healthBar::setMaxHealth(int amount)
{
	if (amount > 0) {
		this->maxhealth = amount;
	}
}

int healthBar::decreaseHealth(int amount)
{
	if (amount >= health) {
		health = 0;
	}
	else {
		this->health -= amount;
	}
	return health;
}

void healthBar::increaseHealth(int amount)
{
	if (amount > 0) {
		this->health += amount;
	}
}

string healthBar::displayBar()
{
	string displayHealth = "HEALTH: ";
	for (int i = 0; i < health; i++)
	{
		displayHealth += "*";
	}
	return displayHealth;
}
