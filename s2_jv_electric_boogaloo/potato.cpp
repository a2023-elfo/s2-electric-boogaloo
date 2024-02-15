#include "potato.h"

char potato::display()
{
    return 'P';
}

void potato::update()
{
    // V�rifier si la patate est touchee par un ennemi 
    if (checkHitBox(x, y)) {
        // Si le peashooter est touchee, r�duire sa sant� de 1
        if (decreaseHealth(1)) {
            // Si la sant� atteint 0 ou moins
            std::cout << "La patate est detruite !" << std::endl;
        }
    }
}

potato::potato(int health, int x, int y)
{
    x = plant.getX();
    y = plant.getY();
    health = 10;
}
