#include "bullet.h"

Bullet::Bullet(int x, int y)
{
	this->setX(x);
	this->setY(y);
}


Bullet::~Bullet()
{
}

char Bullet::display()
{
	return 'B';
}

void Bullet::update()
{
	y = y - 1;
	if (y < 0) {
		// We should delete the bullet, it is out of the grid!
	}
}