#include "gameloop.h"

void gameloop :: readUserInput() {
    char userInput;
    /*if (met tes input ici) {
        Keyboard.write('w');
    }*/
    while (true) {
        if (_kbhit()) {
            userInput = _getch();//fonctionne seulement sur Windows
            switch (userInput) {
            case'w':
                cout << "Avancer" << endl;
                break;
            case 'a':
                cout << "Gauche" << endl;
                break;
            case 's':
                cout << "Reculer" << endl;
                break;
            case 'd':
                cout << "Droite" << endl;
                break;
            case 'q':
                cout << "Pause" << endl;
                break;
            case 'e':
                cout << "Tremblement de terre" << endl;
                break;
            case 'r':
                cout << "Placer plante" << endl;
                break;
            case ' ':
                cout << "Menu - placer plante" << endl;
                break;
            }
        }
    }
}