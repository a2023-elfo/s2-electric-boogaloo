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

void Player::update(vector<Bullet>& bullets, vector<Enemy>& enemies)
{
 //verirfie pour ne pas se tuer avec ses balles
    for (int i = 0; i < (int)bullets.size(); i++) {
        if (checkHitBullet(bullets.at(i)) && bullets.at(i).getBulletType() == friendlyFire) {
            cout << "ouch les bullets font mal a elfo" << endl;
            //TODO implematation barre de vie
        }
    }
    //verirfie dommage enemy
    for (int i = 0; i < (int)enemies.size(); i++) {
        if (checkHitEnemy(enemies.at(i))) {
            cout << "ouch les enemy font mal a elfo" << endl;
            //TODO implematation barre de vie
        }
    }
}
bool Player::checkHitBullet(Bullet& bang)
{
    return bang.getX() == getX() && bang.getY() == getY();
}

bool Player::checkHitEnemy(Enemy& enemy)
{
    return enemy.getX() == getX() && enemy.getY() == getY();
}

