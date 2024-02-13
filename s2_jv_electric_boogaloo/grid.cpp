#include "grid.h"

void grid::update()
{
    // Mettre à jour les ennemis
    for (auto& enemy : enemies) {
    }

    // Mettre à jour les plantes
    for (auto& plant : plants) {
        plant.update();
    }

    // Mettre à jour les balles
    for (auto& bullet : bullets) {
        bullet.update();
    }

    // Mettre à jour le joueur
    playerShooter.update();
}

void grid::display()
{
    // Afficher les ennemis
    for (auto& enemy : enemies) {
        enemy.display();
    }

    // Afficher les plantes
    for (auto& plant : plants) {
        plant.display();
    }

    // Afficher les balles
    for (auto& bullet : bullets) {
        bullet.display();
    }

    // Afficher le joueur
    playerShooter.display();
}

void grid::placePlant(plant p)
{
	// Ajouter la plante 'p' à la liste des plantes dans la grille
	plants.push_back(p);
}
