#include "enemy.h"


bool enemy::checkHitBox(bullet& bang)
{	
	return (bang.getY() == getY() && bang.getX() == getX());
}

//return false if actor has died, else return true
bool enemy::decreaseHealth(int damage)
{
	return (health -= damage) > 0;
}

char enemy::display()
{
	return 'X';
}

void enemy::update(bullet& boom, int deplacement)
{
	setY(getY() + deplacement);

	if (checkHitBox(boom)) {
		decreaseHealth(1);
	}
}

enemy::enemy(int input)
{
	health = input;
}

enemy::enemy()
{
	setHeight(5);
	setWidth(3);
	srand(time(0));
	setX(rand());
	setY(0);
}
