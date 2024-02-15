#include "plant.h"
#include <iostream>

bool plant::checkHitBox(int, int)
{
    return false;
}

bool plant::decreaseHealth(int amount)
{
    // R�duire la sante de la plante de la quantite specifiee (amount)
    health -= amount;
    // V�rifier si la sante est tombee � zero ou moins
    if (health <= 0) {
        // La plante est morte
        return true;
    }
    // La plante est toujours en vie
    return false;
}

char plant::display()
{
    return 'P';
}

void plant::update()
{
    // Mise � jour de l'etat de la plante
    if (checkHitBox(x, y)) {
        // La plante est touchee par un ennemi, reduire sa sante
        if (decreaseHealth(1)) {
            // Si la sante est tombee a zero, la plante est detruite
            std::cout << "La plante a ete detruite !" << std::endl;
        }
    }
}

bullet plant::shoot()
{
    // Cr�er un objet bullet � la position de la plante et le retourner
    return bullet();
}
