#ifndef BULLET_H
#define BULLET_H
#include "displayObject.h"
#include <stdlib.h>
#include <mmsystem.h> 
#pragma comment(lib, "Winmm.lib")

class Bullet:public DisplayObject
{
public:
	Bullet(int _posX, int _posY);
	~Bullet();

	char display();
	void update();

	BulletType getBulletType();
	void setBulletType(BulletType bulletType);
private:
	BulletType bulletType;
};

#endif