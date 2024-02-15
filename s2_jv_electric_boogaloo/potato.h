#ifndef POTATO_H
#define POTATO_H

#pragma once
#include "plant.h"
class potato
{
public:
	char display();
	void update();
	bullet shoot();
	potato(int, int, int);
};

#endif