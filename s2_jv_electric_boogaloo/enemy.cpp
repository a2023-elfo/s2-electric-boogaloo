#include "enemy.h"

bool enemy::checkHitBox()
{
	return false;
}

bool enemy::decreaseHealth(int)
{
	return false;
}

char enemy::display()
{
	return 0;
}

void enemy::update()
{
}

enemy::enemy(int input)
{
	health = input;
}

enemy::enemy()
{
}
