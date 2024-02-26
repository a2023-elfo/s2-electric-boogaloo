#ifndef BULLET_H
#define BULLET_H
#include "displayObject.h"
#include <stdlib.h>

class Bullet:public DisplayObject
{
public:
	Bullet(int _posX, int _posY);
	~Bullet();

	char display();
	void update();
};

#endif