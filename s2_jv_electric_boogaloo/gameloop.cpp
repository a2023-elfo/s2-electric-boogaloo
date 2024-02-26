#include "gameloop.h"

void Gameloop :: readUserInput() {
    char userInput;
    while (true) {
        if (_kbhit()) {
            userInput = _getch();//fonctionne seulement sur Windows
            if (userInput == 'w'/*|| arduino*/) {
                cout << "Avancer" << endl;
            }
            if (userInput == 'a') {
                cout << "Gauche" << endl;
            }
            if (userInput == 's') {
                cout << "Reculer" << endl;
            }
            if (userInput == 'd') {
                cout << "Droite" << endl;
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

void Gameloop :: translateUserInput() {
   
}

void Gameloop :: spawnPlayer() {}
void Gameloop :: spawnEnemy() {}
void Gameloop :: spawnPeashooter() {}
void Gameloop :: spawnPotato() {}
void Gameloop :: tremblementDeTerre() {}