#include "enemy.h"


bool Enemy::checkHitBox(Bullet& bang)
{	
	return (bang.getY() == getY() && bang.getX() == getX());
}

//return false if actor has died, else return true
bool Enemy::decreaseHealth(int damage)
{
	return (health -= damage) > 0;
}

char Enemy::display()
{
	return 'X';
}

void Enemy::update(Bullet& boom, int deplacement)
{
	setY(getY() + deplacement);

	if (checkHitBox(boom)) {
		decreaseHealth(1);
	}
}

Enemy::Enemy(int input)
{
	health = input;
}

Enemy::Enemy()
{
	setHeight(5);
	setWidth(3);
	srand(time(0));
	setX(rand());
	setY(0);
}
