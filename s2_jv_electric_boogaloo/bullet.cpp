#include "bullet.h"

bullet::bullet(int _posX, int _posY)
{
	_posX = x;
	_posY = y;
	width = 1;
	height = 1;
}

bullet::~bullet()
{
}

char bullet::display()
{
	return 'B';
}

void bullet::update()
{
	x = x + 1;
}
