#pragma once
#include "displayObject.h"
#include "bullet.h"

class player:displayObject
{
public:
	player();
	~player();
	void my_up();
	void my_down();
	bullet* shoot();

	char display();
	void update();
};

