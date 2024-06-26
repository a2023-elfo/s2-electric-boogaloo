#include "grid.h"

int gametick = 0;

void Grid::update()
{
    
    bool enemyAvance;

    if (gametick % 9 == 0 && gametick != 0) {
        enemyAvance = true;
    }
    else {
        enemyAvance = false;
    }
    //lol
    // Mettre a jour les ennemis
    for (auto& enemy : enemies) { 
        if (enemyAvance) {
            enemy.setDeplacement(1);
            enemy.update(bullets, potatoes, peaShooters, enemies);
        }
        else {
            enemy.setDeplacement(0);
            enemy.update(bullets, potatoes, peaShooters, enemies);
        }
        
        
    }


    for (auto& peaShooter : peaShooters) {
        // Attack speed. Lower number is higher attack speed
        if (gametick % 6 == 0) {
            peaShooter.update(bullets, 1);
        }
        else {
            peaShooter.update(bullets, 0);
        }
        for (auto& enemy : enemies) {
            if (peaShooter.checkHitBox(enemy.getX(), enemy.getY()) && enemyAvance) {
                peaShooter.decreaseHealth(1);
            }
        }
        
       
    }

     

    for (auto& potato : potatoes) {
        potato.update();
        for (auto& enemy : enemies) {
            if (potato.checkHitBox(enemy.getX(), enemy.getY()) && enemyAvance) {
                potato.decreaseHealth(1);
            }
        }
    }

    // Mettre a jour les balles
    for (auto& bullet : bullets) {
        bullet.update();
        for (int i = 0; i < (int)bullets.size(); i++) {
            if (bullets.at(i).getY() < 0) {
                bullets.erase(bullets.begin() + i);
            }
        }
    }

    // Mettre a jour le joueur
    playerShooter.update(bullets, enemies);
    gametick++;
    
}

void Grid::display()
{

    int x; //position dans la grille
    int y; //position dans la grille

    //Effacer la grille au debut
    for (int i = 0; i < GRID_X; i++) {
        for (int j = 0; j < GRID_Y; j++) {
            grille[i][j] = ' ';
        }
    }

    // Afficher balles
    for (auto& bullet : bullets) {
        x = bullet.getX();
        y = bullet.getY();
        if (x >= 0 && x < GRID_X && y >= 0 && y < GRID_Y) {
            grille[x][y] = bullet.display();
        }
    }

    /// Stockage des enemies dans la grid a afficher
    //Afficher ennemis
    for (auto& enemy : enemies) {
        x = enemy.getX();
        y = enemy.getY();
        
        if (x >= 0 && x < GRID_X && y >= 0 && y < GRID_Y) {
            grille[x][y] = enemy.display();
        }
    }

    for (auto& peaShooter : peaShooters) {
        x = peaShooter.getX();
        y = peaShooter.getY();
        if (x >= 0 && x < GRID_X && y >= 0 && y < GRID_Y) {
            grille[x][y] = peaShooter.display();
        }
    }

    for (auto& potato : potatoes) {
        x = potato.getX();
        y = potato.getY();
        if (x >= 0 && x < GRID_X && y >= 0 && y < GRID_Y) {
            grille[x][y] = potato.display();
        }
    }

    //Afficher joueur
    int playerX = playerShooter.getX();
    int playerY = playerShooter.getY();
    if (playerX >= 0 && playerX < GRID_X && playerY >= 0 && playerY < GRID_Y) {
        grille[playerX][playerY] = playerShooter.display(); //E pour ELFO ofc
    }

    /// Finalement, on affiche!
    //Premiere ligne sont des etoiles
    for (int j = 0; j < GRID_X * 4 + 1; ++j) {
        std::cout << "_";
    }
    std::cout << std::endl;

    for (int i = 0; i < GRID_Y; ++i) {
        for (int j = 0; j < GRID_X; ++j) {
            std::cout << "| " << grille[j][i] << " ";
        }
        std::cout << "|" << std::endl;
    }

    // Dernière ligne
    for (int j = 0; j < GRID_X * 4 + 1; ++j) {
        std::cout << "-";
    }
    std::cout << std::endl;

}


 std::vector<Enemy>& Grid::getEnemies() {
    return enemies;
}

Enemy* Grid::getEnemy(int index) {
    if (index >= 0 && index < enemies.size()) {
        return &enemies[index];
    }
    else {
        return nullptr;
    }
}


Bullet* Grid::getBullet(int index) {
    if (index >= 0 && index < (int)this->bullets.size()) {
        return &bullets[index];
    }
    else {
        return nullptr;
    }
}

 std::vector<Bullet>& Grid::getBullets() {
    return bullets;
}

void Grid::deleteEnemy(int id)
{
    if (id <= enemies.size()){
         enemies.erase((enemies.begin() + id));
    }
}

void Grid::deletePotato(int id)
{
    if (id <= potatoes.size()) {
        potatoes.erase((potatoes.begin() + id));
    }
}

void Grid::deletePeaShooter(int id)
{
    if (id <= peaShooters.size()) {
        peaShooters.erase((peaShooters.begin() + id));
        nbEnemyKilled++;
    }
}

int Grid::getEnemyNumber()
{
    return enemies.size(); 
}

 std::vector<PeaShooter>& Grid::getPeaShooters() {
    return peaShooters;
}
PeaShooter* Grid::getPeaShooter(int index) {
    if (index >= 0 && index < peaShooters.size()) {
        return &peaShooters[index];
    }
    else {
        return nullptr;
    }

}

 std::vector<Potato>& Grid::getPotatoes() {
    return potatoes;
}

Potato* Grid::getPotato(int index) {
    if (index >= 0 && index < potatoes.size()) {
        return &potatoes[index];
    }
    else {
        return nullptr;
    }

}

int Grid::getHealthPlayer() {
    return playerShooter.getHealth();
}
  
