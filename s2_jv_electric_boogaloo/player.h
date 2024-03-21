#ifndef PLAYER_H
#define PLAYER_H
#include "displayObject.h"
#include "enemy.h"
#include <thread>
#include <conio.h>

#include "bullet.h"
#include "healthBar.h"

class Player : public DisplayObject
{
protected : 
	int y = 0;
public:
	Player();
	void move(int offset_x, int offset_y);
	char display();
	void update(std::vector<Bullet>& bullets, std::vector<Enemy>& enemies);
	void setY(int input);
	int getY();

	Bullet* shoot();
	bool checkHitBullet(Bullet& bang);
	bool checkHitEnemy(Enemy& enemy);
	HealthBar health = HealthBar(10);
};

#endif