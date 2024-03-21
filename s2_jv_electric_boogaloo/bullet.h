#ifndef BULLET_H
#define BULLET_H
#include "displayObject.h"
#include <Windows.h>
#include <stdlib.h>
#include <mmsystem.h> 
#pragma comment(lib, "Winmm.lib")

class bullet:public displayObject
{
public:
	bullet(int _posX, int _posY);
	~bullet();

	char display();
	void update();
};

#endif