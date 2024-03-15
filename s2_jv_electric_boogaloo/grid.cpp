#include "grid.h"
#include <iostream>

const int GRID_X = 5;
const int GRID_Y = 10;
char grille[GRID_X][GRID_Y];
int i = 0;




void Grid::update()
{
    i++;
    // Mettre � jour les ennemis
    for (auto& enemy : enemies) { 
        if (i % 15 == 0) {
            enemy.update(bullets, 1);
        }
        else {
            enemy.update(bullets, 0);
        }
        
        
    }


    for (auto& peaShooter : peaShooters) {
        if (i % 5 == 0) {
            peaShooter.update(bullets, 1);
        }
        else {
            peaShooter.update(bullets, 0);
        }
    }

    for (auto& potato : potatoes) {
        potato.update();
    }

    // Mettre � jour les balles
    for (auto& bullet : bullets) {
        bullet.update();
    }

    // Mettre � jour le joueur
    playerShooter.update();
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
    /// Stockage des enemies dans la grid a afficher
    //Afficher ennemis
    for (auto& enemy : enemies) {
        x = enemy.getX();
        y = enemy.getY();
        
        if (x >= 0 && x < GRID_X && y >= 0 && y < GRID_Y) {
            grille[x][y] = enemy.display();
        }
    }
    //Afficher plantes
    /*for (auto& plant : plants) {
        x = plant.getX();
        y = plant.getY();
        if (x >= 0 && x < GRID_X && y >= 0 && y < GRID_Y) {
            grille[x][y] = plant.display();
        }
    }*/

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

    // Afficher balles
    for (auto& bullet : bullets) {
        x = bullet.getX();
        y = bullet.getY();
        if (x >= 0 && x < GRID_X && y >= 0 && y < GRID_Y) {
            grille[x][y] = bullet.display();
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


vector<Enemy>& Grid::getEnemies() {
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

vector<Plant>& Grid::getPlants() {
    return plants;
}

Plant* Grid::getPlant(int index) {
    if (index >= 0 && index < plants.size()) {
        return &plants[index];
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

vector<Bullet>& Grid::getBullets() {
    return bullets;
}

void Grid::deleteEnemy(int id)
{
    if (id <= enemies.size()){
         enemies.erase((enemies.begin() + id));
    }
}

int Grid::getEnemyNumber()
{
    return enemies.size(); 
}

vector<PeaShooter>& Grid::getPeaShooters() {
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

vector<Potato>& Grid::getPotatoes() {
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
  
