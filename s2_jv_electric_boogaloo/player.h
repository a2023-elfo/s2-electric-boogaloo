#ifndef PLAYER_H
#define PLAYER_H
#include "displayObject.h"


#include "bullet.h"

class Player : public DisplayObject
{
public:
	Player();
	void move(int offset_x, int offset_y);
	char display();
	void update();
	Bullet* shoot();

private:
	int chiffre = 0; // Variable temporaire pour l'audit 2

};

#endif