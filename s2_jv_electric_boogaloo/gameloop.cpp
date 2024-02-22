#include "gameloop.h"

void gameloop :: readUserInput() {
    char userInput;
    while (true) {
        if (_kbhit()) {
            userInput = _getch();//fonctionne seulement sur Windows
            if (userInput == 'w'/*|| arduino*/) {
                cout << "Avancer" << endl;
                joueur.setY(joueur.getY() - 1);
            }
            if (userInput == 'a') {
                cout << "Gauche" << endl;
                joueur.setX(joueur.getY() - 1);
            }
            if (userInput == 's') {
                cout << "Reculer" << endl;
                joueur.setY(joueur.getY() + 1);
            }
            if (userInput == 'd') {
                cout << "Droite" << endl;
                joueur.setX(joueur.getY() + 1);
            }
            if (userInput == 'q') {
                cout << "Pause" << endl;
            }
            if (userInput == 'e') {
                cout << "Tremblement de terre" << endl;
                //super();
            }
            if (userInput == 'r') {
                cout << "PLacer plante" << endl;
                //changer menu? ou bouger Elfo position?
            }
            if (userInput == ' ') {
                cout << "Tirer" << endl;
            }
        }
    }
}

void gameloop :: translateUserInput() {
   
}

void gameloop :: spawnPlayer() {}
void gameloop :: spawnEnemy() {}
void gameloop :: spawnPeashooter() {}
void gameloop :: spawnPotato() {}
void gameloop :: tremblementDeTerre() {}