#include "player.h"

player::player()
{
    x = 0;
    y = 0;
    width = 1;
    height = 1;
}

player::~player()
{
}

void player::my_up()
{
    if(y != 0) y = y - 1;
}

void player::my_down()
{
    if(y != 5) y = y + 1;
}

bullet* player::shoot()
{
    bullet* b = new bullet(x,y);
    return b;
}

char player::display()
{
    return 'P';
}

void player::update()
{
    for (int i = 0; i < 5; i++) { //Pour tester
        my_down();
    }
    for (int i = 0; i < 5; i++) {
        my_up();
    }
}