#ifndef BULLET_H
#define BULLET_H
#include "displayObject.h"
#include "player.h"
#include <stdlib.h>

class bullet:displayObject
{
public:
	bullet(int _posX, int _posY);
	~bullet();

	char display();
	void update();
};

#endif