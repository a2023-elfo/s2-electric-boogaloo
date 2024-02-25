#include "potato.h"

char potato::display()
{
    return 'P';
}

void potato::update()
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

potato::potato(int x, int y, int health)
{
    setX(x);
    setY(y);
    this->health = health;
}
