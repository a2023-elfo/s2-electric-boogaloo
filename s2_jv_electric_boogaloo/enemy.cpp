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

void enemy::update(vector<bullet>& bullets, int deplacement)
{
	setY(getY() + deplacement);

	for (int i = 0; i < (int)bullets.size(); i++) {
		if (checkHitBox(bullets.at(i))) {
			decreaseHealth(1);
		}
	}
	
}

enemy::enemy(int _health, int x)
{
	health = _health;
	setHeight(5);
	setWidth(3);
	setX(x);
	setY(0);
}

int enemy::getHealth() {
	return health;
}

/*enemy::enemy()
{
	setHeight(5);
	setWidth(3);
	srand(time(0));
	setX(rand());
	setY(0);
}*/
