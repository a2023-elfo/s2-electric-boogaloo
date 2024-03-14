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

void Enemy::update(vector<Bullet>& bullets, int deplacement)
{
	setY(getY() + deplacement);

	for (int i = 0; i < (int)bullets.size(); i++) {
		if (checkHitBox(bullets.at(i))) {
			decreaseHealth(1);
		}
	}
	
}

Enemy::Enemy(int _health, int x)
{
	health = _health;
	setHeight(5);
	setWidth(3);
	setX(x);
	setY(0);
}

int Enemy::getHealth() {
	return health;
}