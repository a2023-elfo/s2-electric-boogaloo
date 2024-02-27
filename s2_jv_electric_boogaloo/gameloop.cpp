#include "gameloop.h"
#include "thread"

void Gameloop::gameOver() {
    std::system("cls");
    std::cout << "GAME OVER" << std::endl;
}

void Gameloop::spawnEnemy(int enemyPos, bool theRock) {

    int health = 0;
    int position = 0;
    switch (enemyPos) {
    case 0:
        health = 5;
        position = 0;
        break;
    case 1:
        health = 5;
        position = 1;
        break;
    case 2:
        health = 5;
        position = 2;
        break;
    case 3:
        health = 5;
        position = 3;
        break;
    case 4:
        health = 5;
        position = 4;
        break;
    }
    if (theRock) {
        health = 20;
    }
    Enemy zombie(health, position);
    arene.getEnemies().push_back(zombie);
}

void Gameloop :: readUserInput() {
    char userInput;
    charge = 0;
    spawnEnemy(0,0);
    spawnEnemy(1,0);
    spawnEnemy(2,1);
    spawnEnemy(3,0);
    spawnEnemy(4,0);
    arene.display();
    while (true) {
        std::this_thread::sleep_for(250ms);
        if (_kbhit()) {
            userInput = _getch();//fonctionne seulement sur Windows
            if (userInput == 'w'/*|| arduino*/) {
                cout << "Avancer" << endl;
                arene.playerShooter.setY(arene.playerShooter.getY() - 1);
            }
            if (userInput == 'a') {
                cout << "Gauche" << endl;
                arene.playerShooter.setX(arene.playerShooter.getX() - 1);
            }
            if (userInput == 's') {
                cout << "Reculer" << endl;
                arene.playerShooter.setY(arene.playerShooter.getY() + 1);
            }
            if (userInput == 'd') {
                cout << "Droite" << endl;
                arene.playerShooter.setX(arene.playerShooter.getX() + 1);
            }
            if (userInput == 'q') {
                cout << "Do nothing" << endl;
            }
            if (userInput == 'e') {
                cout << "Tremblement de terre" << endl;
                tremblementDeTerre(charge);
            }
            if (userInput == 't') {
                cout << "Placer potato" << endl;
                spawnPotato(10);
            }
            if (userInput == 'r') {
                cout << "Placer peashooter" << endl;
                spawnPeashooter(3);
            }
            if (userInput == ' ') {
                cout << "Tirer" << endl;
                arene.getBullets().push_back(*arene.playerShooter.shoot());
            }
        }
        arene.update();
        std::system("cls");
        arene.display();
        std::vector<Enemy> zombieMort;
        for (int i = 0; i < arene.getEnemies().size();) {

            if (arene.getEnemies()[i].getY() == 9 || arene.getEnemies()[i].getHealth() <= 0) {

                zombieMort.push_back(arene.getEnemies()[i]);
                arene.deleteEnemy(i);
                if(arene.getEnemyNumber() <= 0) {
                    gameOver();
                }

            }
            else {
                i++;
            }
        }
        charge += (int)zombieMort.size();
        zombieMort.clear();
    }
}

void Gameloop :: translateUserInput() {
   
}



void Gameloop :: spawnPeashooter(int health) {
    PeaShooter piouPiou(health, arene.playerShooter.getX(), arene.playerShooter.getY() + 1);
    arene.getPlants().push_back(piouPiou);
}
void Gameloop :: spawnPotato(int health) {
    PeaShooter bigMama(health, arene.playerShooter.getX(), arene.playerShooter.getY() + 1);
    arene.getPlants().push_back(bigMama);

}
void Gameloop:: tremblementDeTerre(int charge) {
    for (int i = 0; i < arene.getEnemies().size(); i++) {
        arene.getEnemies()[i].decreaseHealth(charge);
    }
    charge = 0;
}

