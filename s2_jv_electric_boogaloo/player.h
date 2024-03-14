#ifndef PLAYER_H
#define PLAYER_H
#include "displayObject.h"
#include "enemy.h"
#include <thread>
#include <conio.h>

#include "bullet.h"

class Player : public DisplayObject
{
public:
	Player();
	void move(int offset_x, int offset_y);
	char display();
	void update(std::vector<Bullet>& bullets, std::vector<Enemy>& enemies);

	Bullet* shoot();
	bool checkHitBullet(Bullet& bang);
	bool checkHitEnemy(Enemy& enemy);

private:
	int chiffre = 0; // Variable temporaire pour l'audit 2

};

#endif