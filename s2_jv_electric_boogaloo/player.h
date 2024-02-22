#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include "displayObject.h"
class player: public displayObject
{
	char display();
	void update();
};

#endif

