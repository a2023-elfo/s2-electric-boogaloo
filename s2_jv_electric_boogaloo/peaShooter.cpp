#include "peaShooter.h"

char peaShooter::display()
{
    return 'P';
}

void peaShooter::update()
{
    // Vérifier si le pea shooter est touche par un ennemi 
    if (checkHitBox(x, y)) {
        // Si le peashooter est touche
        if (decreaseHealth(1)) {
            // Si la sante atteint 0 ou moins
            std::cout << "Le pea shooter est détruit !" << std::endl;
        }
    }
}

bullet peaShooter::shoot(){
    int xBullet = bullet.getX();
    int yBullet = bullet.getY() + 1;
    return bullet(xBullet, yBullet);
}

peaShooter::peaShooter(int health, int x, int y)
{
    x = plant.getX();
    y = plant.getY();
    health = 5;
}