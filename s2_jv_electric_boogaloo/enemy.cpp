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
	return apparence;
}


void Enemy::update(vector<Bullet>& bullets, vector<Potato> potatoes, vector<PeaShooter> peaShooters, vector<Enemy>& enemies)
{
	
	for (int i = 0; i < (int)potatoes.size(); i++) {
		if (getY() + 1 == potatoes[i].getY() && getX() == potatoes[i].getX()) {
			setDeplacement(0);
			
		}
	}
	for (int i = 0; i < (int)peaShooters.size(); i++) {
		if (getY() + 1 == peaShooters[i].getY() && getX() == peaShooters[i].getX()) {
			setDeplacement(0);

		}
	}
	for (int i = 0; i < (int)enemies.size(); i++) {
		if (getY()+1 == enemies[i].getY() && getX() == enemies[i].getX()) {
			setDeplacement(0);

		}
	}
	
	setY(getY() + deplacement);

	for (int i = 0; i < (int)bullets.size(); i++) {
		if (checkHitBox(bullets.at(i))) {
			decreaseHealth(1);
		}
	}
}

Enemy::Enemy(int _health, int x, char appearance)
{
	setDeplacement(1);
	health = _health;
	setHeight(5);
	setWidth(3);
	setX(x);
	setY(0);
	apparence = appearance;
}

int Enemy::getHealth() {
	return health;
}

void Enemy::setDeplacement(int mouvement)
{
	deplacement = mouvement;
}
