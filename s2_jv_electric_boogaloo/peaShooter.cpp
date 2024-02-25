#include "peaShooter.h"

char peaShooter::display()
{
    return 'P';
}

void peaShooter::update()
{
    // Verifier si le pea shooter est touche par un ennemi 
    if (checkHitBox(x, y)) {
        // Si le peashooter est touche
        if (decreaseHealth(1)) {
            // Si la sante atteint 0 ou moins
            std::cout << "Le pea shooter est d�truit !" << std::endl;
        }
    }
}

bullet peaShooter::shoot(){
    int xBullet = this->getX();
    int yBullet = this->getY() + 1;
    return bullet(xBullet, yBullet);
}

peaShooter::peaShooter(int x, int y, int health)
{
    this->setX(x);
    this->setY(y);
    this->health = health;
}