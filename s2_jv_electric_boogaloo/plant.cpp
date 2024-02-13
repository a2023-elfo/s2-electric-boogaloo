#include "plant.h"

bool plant::checkHitBox(int, int)
{
    return false;
}

bool plant::decreaseHealth(int)
{
    return false;
}

char plant::display()
{
    return 'X';
}

void plant::update()
{
    cout << "update plante non overwriter\n";
}

bullet plant::shoot()
{
    return bullet();
}
