#include "plant.h"

bool Plant::checkHitBox(int, int)
{
    return false;
}

int Plant::getHealth()
{
    return this->health;
}

// Returns false once plant has died
bool Plant::decreaseHealth(int amount)
{
    // Reduire la sante de la plante de la quantite specifiee (amount)
    health -= amount;

    return health > 0;
}

char Plant::display()
{
    return 'P';
}

void Plant::update()
{
    // Mise à jour de l'etat de la plante
    if (checkHitBox(x, y)) {
        // La plante est touchee par un ennemi, reduire sa sante
        if (decreaseHealth(1)) {
            // Si la sante est tombee a zero, la plante est detruite
            std::cout << "La plante a ete detruite !" << std::endl;
        }
    }
}
