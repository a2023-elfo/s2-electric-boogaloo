#include <iostream>
#include <string>

#include "gameloop.h"
#include "thread"
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
using json = nlohmann::json;

/*------------------------------ Constantes ---------------------------------*/
#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message


/*------------------------- Prototypes de fonctions -------------------------*/
bool SendToSerial(SerialPort* arduino, json j_msg);
bool RcvFromSerial(SerialPort* arduino, string& msg);

SerialPort* arduino; //doit etre un objet global!


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
    bool loop = true;
    charge = 0;
    spawnEnemy(0,0);
    spawnEnemy(1,0);
    spawnEnemy(2,1);
    spawnEnemy(3,0);
    spawnEnemy(4,0);
    arene.display();

    string raw_msg;

    //Struct. Donn�es JSON 
    int recuX = 0;
    int recuY = 0;
    int bouton = 0;

    // Initialisation du port de communication
    string com;
    cout << "Entrer le port de communication du Arduino: ";
    cin >> com;
    arduino = new SerialPort(com.c_str(), BAUD);

    if (!arduino->isConnected()) {
        cerr << "Impossible de se connecter au port " << string(com) << ". Fermeture du programme!" << endl;
        exit(1);
    }
    else {
        cout << "Connexion OK " << endl;
    }
    
    // Structure de donnees JSON pour envoie et reception
    json j_msg_send, j_msg_rcv;

    while (loop) {
        std::this_thread::sleep_for(250ms);

        // Envoie message Arduino
        j_msg_send["Affichage"] = "X=" + to_string(recuX) + " Y=" + to_string(recuY) + " B=" + to_string(bouton);


        // Reception message Arduino

        if (!SendToSerial(arduino, j_msg_send)) {
            cerr << "Erreur lors de l'envoie du message. " << endl;
        }


        j_msg_rcv.clear();
        if (!RcvFromSerial(arduino, raw_msg)) {
            cerr << "Erreur lors de la reception du message. " << endl;
            break;
        }


        // Impression du message de l'Arduino si valide
        if (raw_msg.size() > 0) {
            // cout << "raw_msg: " << raw_msg << endl;  // debug
            // Transfert du message en json
            j_msg_rcv = json::parse(raw_msg);


            recuX = j_msg_rcv.value("X", 0);
            recuY = j_msg_rcv.value("Y", 0);
            bouton = j_msg_rcv.value("Bouton", 0);


        }
        if (_kbhit()) {
            userInput = _getch();
        }
        else {
            userInput = '/';
        }

        if (userInput == 'w' || (recuX == 0 && recuY == 1)) {
            cout << "Avancer" << endl;
            arene.playerShooter.setY(arene.playerShooter.getY() - 1);
        }
        
        if (userInput == 'a' || (recuX == -1 && recuY == 0)) {
            cout << "Gauche" << endl;
            arene.playerShooter.setX(arene.playerShooter.getX() - 1);
        }
        if (userInput == 's' || (recuX == 0 && recuY == -1)) {
            cout << "Reculer" << endl;
            arene.playerShooter.setY(arene.playerShooter.getY() + 1);
        }
        if (userInput == 'd' ||( recuX == 1 && recuY == 0)) {
            cout << "Droite" << endl;
            arene.playerShooter.setX(arene.playerShooter.getX() + 1);
        }
        if (userInput == 'q'/* || bouton = ++ */ ) {
            cout << "Do nothing" << endl;
        }
        if (userInput == 'e') {
            cout << "Tremblement de terre" << endl;
            tremblementDeTerre(charge);
        }
        if (userInput == 't'|| bouton == 3) {
            cout << "Placer potato" << endl;
            spawnPotato(10);
        }
        if (userInput == 'r'|| bouton == 4) {
            cout << "Placer peashooter" << endl;
            spawnPeashooter(3);
        }
        if (userInput == ' '|| bouton==1) {
            cout << "Tirer" << endl;
            arene.getBullets().push_back(*arene.playerShooter.shoot());
        }

        arene.update();
        
        std::system("cls");
        arene.display();
        std::vector<Enemy> zombieMort;
        for (int i = 0; i < arene.getEnemies().size();) {

            if (arene.getEnemies()[i].getY() == 9 || arene.getEnemies()[i].getHealth() <= 0) {

                zombieMort.push_back(arene.getEnemies()[i]);
                arene.deleteEnemy(i);
                if (arene.getEnemyNumber() <= 0) {
                    loop = false;
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
    PeaShooter piouPiou(health, arene.playerShooter.getX(), arene.playerShooter.getY() - 1);
    arene.getPeaShooters().push_back(piouPiou);
}
void Gameloop :: spawnPotato(int health) {
    Potato bigMama(health, arene.playerShooter.getX(), arene.playerShooter.getY() - 1);
    arene.getPotatoes().push_back(bigMama);

}
void Gameloop:: tremblementDeTerre(int charge) {
    for (int i = 0; i < arene.getEnemies().size(); i++) {
        arene.getEnemies()[i].decreaseHealth(charge);
    }
    charge = 0;
}

/*---------------------------Definition de fonctions JSON------------------------*/
bool SendToSerial(SerialPort* arduino, json j_msg) {
    // Return 0 if error
    string msg = j_msg.dump();
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}


bool RcvFromSerial(SerialPort* arduino, string& msg) {
    // Return 0 if error
    // Message output in msg
    string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear string
// Version fonctionnelle dans VScode et Visual Studio
    buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);
    return true;
}


