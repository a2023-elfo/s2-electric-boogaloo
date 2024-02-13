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

int plant::getX() {

}

int plant::getY() {

}

void plant::update()
{
    cout << "update plante non overwriter\n";
}

bullet plant::shoot()
{
    return bullet();
}
