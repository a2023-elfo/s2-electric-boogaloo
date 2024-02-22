#include "potato.h"

char potato::display()
{
    return 'P';
}

void potato::update()
{
    // Vérifier si la patate est touchee par un ennemi 
    if (checkHitBox(x, y)) {
        // Si le peashooter est touchee, réduire sa santé de 1
        if (decreaseHealth(1)) {
            // Si la santé atteint 0 ou moins
            std::cout << "La patate est detruite !" << std::endl;
        }
    }
}

bullet potato::shoot()
{
    return bullet(x,y);
}

potato::potato(int health, int x, int y)
{
    x = plant.getX();
    y = plant.getY();
    health = 10;
}
