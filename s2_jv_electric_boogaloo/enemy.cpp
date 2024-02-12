
#include "enemy.h"


bool enemy::checkHitBox(bullet& bang)
{	
	return (bang.getY() == getY() && bang.getX() == getX());
}

bool enemy::decreaseHealth(int damage)
{
	health -= damage;
	return true;
	
}

char enemy::display()
{
	return 'X';
}

void enemy::update(bullet& boom)
{
	setY(getY() - 1);

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
	//int health = 3;
	setHeight(5);
	setWidth(3);
	srand(time(0));
	setX(rand() % 6 + 1);
	setY(0);
	
}
