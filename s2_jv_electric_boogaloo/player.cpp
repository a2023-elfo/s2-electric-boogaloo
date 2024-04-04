#include "player.h"

Player::Player()
{
    x = 2;
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

void Player::update( std::vector<Bullet>& bullets, std::vector<Enemy>& enemies)
{
    //verirfie pour ne pas se tuer avec ses balles
    for (int i = 0; i < (int)bullets.size(); i++) {
        if (checkHitBullet(bullets.at(i)) && bullets.at(i).getBulletType() == friendlyFire) {
            std::cout << "ouch les bullets font mal a elfo" << std::endl;
            health.decreaseHealth(1);
        }
    }
    //verirfie dommage enemy
    for (int i = 0; i < (int)enemies.size(); i++) {
        if (checkHitEnemy(enemies.at(i))) {
            std::cout << "ouch les enemy font mal a elfo" << std::endl;
            health.decreaseHealth(1);
        }
    }
}
void Player::setY(int input)
{
    if (input < 2) {
        y = 2;
    }
    else if (input > 9) {
        y = 9;
    }
    else {
        y = input;
    }
}
int Player::getY()
{
    return y;
}
bool Player::checkHitBullet(Bullet& bang)
{
    return bang.getX() == getX() && bang.getY() == getY();
}

bool Player::checkHitEnemy(Enemy& enemy)
{
    return enemy.getX() == getX() && enemy.getY() == getY();
}

