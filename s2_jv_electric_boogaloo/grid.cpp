#include "grid.h"
#include <iostream>

const int GRID_X = 5;
const int GRID_Y = 10;
char grille[GRID_X][GRID_Y];

void Grid::update()
{
    // Mettre � jour les ennemis
    for (auto& enemy : enemies) {
        // This will be changed by Zac's code!
        //enemy.update();
    }

    // Mettre � jour les plantes
    for (auto& plant : plants) {
        plant.update();
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
    for (auto& plant : plants) {
        x = plant.getX();
        y = plant.getY();
        if (x >= 0 && x < GRID_X && y >= 0 && y < GRID_Y) {
            grille[x][y] = plant.display();
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
    if (playerX >= 0 && playerX < 10 && playerY >= 0 && playerY < 5) {
        grille[playerY][playerX] = playerShooter.display(); //E pour ELFO ofc
    }

    /// Finalement, on affiche!
    //Premiere ligne sont des etoiles
    for (int j = 0; j < GRID_X * 4 + 1; ++j) {
        std::cout << "*";
    }
    std::cout << std::endl;

    for (int i = 0; i < GRID_Y; ++i) {
        for (int j = 0; j < GRID_X; ++j) {
            std::cout << "* " << grille[j][i] << " ";
        }
        std::cout << "*" << std::endl;
    }

    // Dernière ligne
    for (int j = 0; j < GRID_X * 4 + 1; ++j) {
        std::cout << "*";
    }
    std::cout << std::endl;

}

void Grid::placePlant(Plant plant)
{
	// Ajouter la plante 'p' � la liste des plantes dans la grille
	plants.push_back(plant);
}
