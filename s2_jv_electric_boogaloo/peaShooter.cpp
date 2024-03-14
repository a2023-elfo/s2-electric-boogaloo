#include "peaShooter.h"


char PeaShooter::display()
{
    return 'P';
}

void PeaShooter::update(std::vector<Bullet>& bullets, bool fire) 
{
    
    if (checkHitBox(x, y)) {
        // Si le peashooter est touchee, reduire sa sante de 1
        if (!decreaseHealth(1)) {
            // Si la sante atteint 0 ou moins
            std::cout << "La patate est detruite !" << std::endl;
        }
    }

    if (fire) {
        bullets.push_back(*shoot());
    }
    
}

Bullet* PeaShooter::shoot(){
    
    return new Bullet(this->getX() , this->getY());
    
}

PeaShooter::PeaShooter(int health, int x, int y)
{
    health = 5;
    this->setX(x);
    this->setY(y);
    this->health = health;
}