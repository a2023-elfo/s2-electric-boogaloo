#include "peaShooter.h"

char PeaShooter::display()
{
    return 'P';
}

void PeaShooter::update()
{
    // Verifier si le pea shooter est touche par un ennemi 
    if (checkHitBox(x, y)) {
        // Si le peashooter est touche
        if (decreaseHealth(1)) {
           // Si la sante atteint 0 ou moins
            std::cout << "Le pea shooter est détruit !" << std::endl;
        }
    }
}

Bullet* PeaShooter::shoot(){
    int xBullet = this->getX();
    int yBullet = this->getY() + 1;
    return new Bullet(xBullet, yBullet);
}

PeaShooter::PeaShooter(int x, int y, int health)
{
    this->setX(x);
    this->setY(y);
    this->health = health;
}