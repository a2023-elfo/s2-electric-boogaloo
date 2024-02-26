#include "potato.h"

char Potato::display()
{
    return 'P';
}

void Potato::update()
{
    // Verifier si la patate est touchee par un ennemi 
    if (checkHitBox(x, y)) {
        // Si le peashooter est touchee, reduire sa sante de 1
        if (!decreaseHealth(1)) {
            // Si la sante atteint 0 ou moins
            std::cout << "La patate est detruite !" << std::endl;
        }
    }
}

Potato::Potato(int x, int y, int health)
{
    setX(x);
    setY(y);
    this->health = health;
}
