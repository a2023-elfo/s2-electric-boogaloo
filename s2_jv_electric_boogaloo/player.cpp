#include "player.h"

Player::Player()
{
    x = 0;
    y = 9;
    width = 1;
    height = 1;
}

Bullet* Player::shoot()
{
    return new Bullet(this->getX(), this->getY());
}

char Player::display()
{
    return 'E';
}

void Player::move(int offset_x, int offset_y) {
    // TODO, move player towards offset, but prevent from going out of bounds
}

void Player::update()
{
    // Audit 2 update behaviour, just to see if the movement works
    if (chiffre % 2) { // 1, 3, 5 on va
        if (getX() > 1) {
            setX(getX() - 1);
        }
        else {
            chiffre++;
            update();
        }
    }
    else { // 0, 2, 4. On va vers la droite
        if (getX() < 4) {
            setX(getX() + 1);
        } else {
            chiffre++;
            update();
        }
    }
}