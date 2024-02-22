#include "grid.h"
#include <iostream>

char grille[5][10];

void grid::update()
{
    // Mettre � jour les ennemis
    for (auto& enemy : enemies) {
        enemy.update();
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

void grid::display()
{
    int x; //position dans la grille
    int y; //position dans la grille

    //Effacer la grille au d�but
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            grille[i][j] = '0';
        }
    }
    //Afficher ennemis
    for (auto& enemy : enemies) {
        x = enemy.getX();
        y = enemy.getY();
        
        if (x >= 0 && x < 10 && y >= 0 && y < 5) {
            grille[y][x] = 'X';
        }
    }
    //Afficher plantes
    for (auto& plant : plants) {
        x = plant.getX();
        y = plant.getY();
        if (x >= 0 && x < 10 && y >= 0 && y < 5) {
            grille[y][x] = 'P';
        }
    }
    // Afficher balles
    for (auto& bullet : bullets) {
        x = bullet.getX();
        y = bullet.getY();
        if (x >= 0 && x < 10 && y >= 0 && y < 5) {
            grille[y][x] = 'B';
        }
    }
    //Afficher joueur
    int playerX = playerShooter.getX();
    int playerY = playerShooter.getY();
    if (playerX >= 0 && playerX < 10 && playerY >= 0 && playerY < 5) {
        grille[playerY][playerX] = 'E'; //E pour ELFO ofc
    }
    //Premiere ligne sont des �toiles
    for (int j = 0; j < 10; ++j) {
        std::cout << "* ";
    }
    std::cout << std::endl;
    //Afficher grille
    for (int j = 0; j < 10; ++j) {
        std::cout << "* ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cout << "* "; // Afficher un * au d�but de chaque ligne
        for (int j = 0; j < 10; ++j) {
            std::cout << grille[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void grid::placePlant(plant p)
{
	// Ajouter la plante 'p' � la liste des plantes dans la grille
	plants.push_back(p);
}
