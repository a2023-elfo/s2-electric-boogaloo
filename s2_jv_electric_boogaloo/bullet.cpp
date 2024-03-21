#include "bullet.h"

bullet::bullet(int _posX, int _posY)
{
	this->setX(x);
	this->setY(y);
	bulletType = notFriendlyFire;	
}

bullet::~bullet()
{
}

char bullet::display()
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

Bullet::BulletType Bullet::getBulletType()
{
	return bulletType;
}

void Bullet::setBulletType(BulletType type)
{
	x = x + 1;
}
