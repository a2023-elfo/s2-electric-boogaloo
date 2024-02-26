#include "gameloop.h"


void gameloop::gameOver() {

    std::system("cls");
    std::cout << "GAME OVER" << std::endl;
}

void gameloop::spawnEnemy(int enemyType) {

    switch (enemyType) {

    case 0:
        enemy John;
        John = enemy(5, 0);
        arene.enemies.push_back(John);
        break;
    case 1:
        enemy Bob;
        Bob = enemy(5, 1);
        arene.enemies.push_back(Bob);
        break;
    case 2:
        enemy TheRock;
        TheRock = enemy(10, 2);
        arene.enemies.push_back(TheRock);
        break;
    case 3:
        enemy Bine;
        Bine = enemy(5, 3);
        arene.enemies.push_back(Bob);
        break;
    case 4:
        enemy Joe;
        Joe = enemy(5, 4);
        arene.enemies.push_back(Joe);
        break;
    }

}


void gameloop :: readUserInput() {
    char userInput;
    spawnEnemy(0);
    spawnEnemy(1);
    //spawnEnemy(2);
    spawnEnemy(3);
    spawnEnemy(4);
    arene.display();
    while (true) {
        if (_kbhit()) {
            userInput = _getch();//fonctionne seulement sur Windows
            if (userInput == 'w'/*|| arduino*/) {
                cout << "Avancer" << endl;
                arene.playerShooter.setX(arene.playerShooter.getY() - 1);
            }
            if (userInput == 'a') {
                cout << "Gauche" << endl;
                arene.playerShooter.setX(arene.playerShooter.getX() - 1);
            }
            if (userInput == 's') {
                cout << "Reculer" << endl;
                arene.playerShooter.setX(arene.playerShooter.getY() + 1);
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
                tremblementDeTerre();
            }
            if (userInput == 'r') {
                cout << "Placer plante" << endl;
                //changer menu? ou bouger Elfo position?
            }
            if (userInput == ' ') {
                cout << "Tirer" << endl;
                arene.playerShooter.shoot();
            }
        }
        arene.update();
        arene.display();
        std::vector<Enemy> zombieMort;// a modifier pour inclure tous les zombies mort
        for (int i = 0; i < arene.enemies.size(); i++) {
            if (arene.enemies[i].getY() == 9 || arene.enemies[i].getHealth() <= 0) {
                zombieMort.push_back(arene.enemies[i]);
                if (arene.enemies[i].getY() == 9) {
                    gameOver();
                }
            }
        }
        zombieMort.clear();
    }
}

void gameloop :: translateUserInput() {
   
}



void gameloop :: spawnPeashooter() {}
void gameloop :: spawnPotato() {}
void gameloop :: tremblementDeTerre() {}

