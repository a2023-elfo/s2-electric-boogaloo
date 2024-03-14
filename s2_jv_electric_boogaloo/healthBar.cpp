#include "healthBar.h"

healthBar::healthBar(int baseHealth)
{
	if (baseHealth > 0) {
		this->setMaxHealth(baseHealth);
		this->setHealth(baseHealth);
	}
}

void healthBar::setHealth(int amount)
{
	if (amount > 0) {
	        if (amount > this->getMaxHealth()) {
		        this->health = this->getMaxHealth();
	        } else {
		        this->health = amount;
	        }
	} else {
	        this->health = 0;
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
		this->health = maxhealth;
	}
	else {
		this->maxhealth = 1;
		this->health = 1;
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
		if (this->health > this->maxhealth) {
			this->health = maxhealth;
		}
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
