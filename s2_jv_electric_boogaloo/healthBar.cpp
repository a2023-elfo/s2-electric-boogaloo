#include "healthBar.h"

HealthBar::HealthBar(int baseHealth)
{
	if (baseHealth > 0) {
		this->setMaxHealth(baseHealth);
		this->setHealth(baseHealth);
	}
}

void HealthBar::setHealth(int amount)
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

int HealthBar::getHealth()
{
	return health;
}

int HealthBar::getMaxHealth()
{
	return maxhealth;
}

void HealthBar::setMaxHealth(int amount)
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

int HealthBar::decreaseHealth(int amount)
{
	if (amount >= health) {
		health = 0;
	}
	else {
		this->health -= amount;
	}
	return health;
}

void HealthBar::increaseHealth(int amount)
{
	if (amount > 0) {
		this->health += amount;
		if (this->health > this->maxhealth) {
			this->health = maxhealth;
		}
	}
}

std::string HealthBar::displayBar()
{
	std::string displayHealth = "HEALTH: ";
	for (int i = 0; i < health; i++)
	{
		displayHealth += "*";
	}
	return displayHealth;
}
