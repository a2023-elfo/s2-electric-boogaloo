#pragma once
#include "displayObject.h"


class bullet:public displayObject
{
public:
	char display();
	void update();
};

