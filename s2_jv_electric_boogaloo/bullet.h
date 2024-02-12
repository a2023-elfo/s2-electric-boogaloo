#ifndef BULLET_H
#define BULLET_H

#pragma once
#include "displayObject.h"


class bullet: public displayObject
{
public:
	char display();
	void update();
};

#endif