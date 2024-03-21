#include "bullet.h"

Bullet::Bullet(int x, int y)
{
	this->setX(x);
	this->setY(y);
	bulletType = notFriendlyFire;
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
}

Bullet::BulletType Bullet::getBulletType()
{
	return bulletType;
}

void Bullet::setBulletType(BulletType type)
{
	bulletType = type;
}