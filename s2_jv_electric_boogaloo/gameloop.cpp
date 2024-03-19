#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "gameloop.h"
#include "thread"
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
#include "enums.h"
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

void Gameloop::setupDirector() {
    // Set base of random, current time
    // For debug, replace director random for a known value and the same result will happen every time
    auto currentTime = std::chrono::system_clock::now().time_since_epoch();
    directorRandom = std::chrono::duration_cast<std::chrono::seconds>(currentTime).count();
}

void Gameloop::inputUpdateDirector(vector<GameControls>& inputVect) {
    directorRandom++;
    for (int i = 0; i < inputVect.size(); i++) {
        directorRandom += (long)inputVect.at(i);
    }
}

int Gameloop::generateValue(int min, int max) {
    int range = std::abs(max - min);

    if (range == 0) {
        return 1;
    }
    else {
        int value = directorRandom % range;
        value += min;
        directorRandom += 3; // Offset random for next generated value
        return value;
    }
}

void Gameloop::generateEnemy() {
    // Add funds for trying to generate
    directorFunds += generateValue(1, 25);


    // Try to generate enemy if sufficient funds
    if (directorFunds >= NORMAL && generateValue(1, 10) == 1) { // Enough funds. If we get more types, this algorithm will have to change
        
        // We are spawning an enemy, choose position
        int desiredPosition = generateValue(0, arene.GRID_X - 1);

        if (arene.grille[desiredPosition][0] == ' ') {  // Empty, we can spawn
            spawnEnemy(desiredPosition, false);
        }
    }
}

bool Gameloop::checkPlayerInput(GameControls checkedInput, vector<GameControls>& inputVect) {
    return std::find(inputVect.begin(), inputVect.end(), checkedInput) != inputVect.end();
}

void Gameloop::mainLoop() {
    char userInput;
    bool loop = true;
    charge = 0;
    arene.display();

    string raw_msg;

    //Struct. Donn�es JSON 
    int bouge = 0;
    int bouton = 0;

    // Initialisation du port de communication
    string com;
    cout << "Entrer le port de communication du Arduino: ";
    cin >> com;
    bool keyboardOnly = com == "ELFO";

    arduino = new SerialPort(com.c_str(), BAUD);

    if (!arduino->isConnected() && !keyboardOnly) {
        cerr << "Impossible de se connecter au port " << string(com) << ". Fermeture du programme!" << endl;
        exit(1);
    }
    else {
        cout << "Connexion OK " << endl;
    }
    
    // Structure de donnees JSON pour envoie et reception
    json j_msg_send, j_msg_rcv;
    std::vector<GameControls> inputs;

    while (loop) {

        // Envoie message Arduino
        j_msg_send["Affichage"] = "Mouvement" + to_string(bouge) + " B=" + to_string(bouton);

        if (!keyboardOnly) {
            if (!SendToSerial(arduino, j_msg_send)) {
                cerr << "Erreur lors de l'envoie du message. " << endl;
            }

            // Reception message Arduino
            if (!RcvFromSerial(arduino, raw_msg)) {
                cerr << "Erreur lors de la reception du message. " << endl;
                break;
            }
        }

        // Impression du message de l'Arduino si valide
        if (raw_msg.size() > 0) {
            // cout << "raw_msg: " << raw_msg << endl;  // debug
            // Transfert du message en json
            j_msg_rcv = json::parse(raw_msg);

            bouge = j_msg_rcv.value("mouvement", 0);
            bouton = j_msg_rcv.value("Bouton", 0);
        }
        else {
            j_msg_rcv = json::parse(R"({})");
        }


        // Lecture de l'input du joueur
        inputs = readUserInput(j_msg_rcv);

        if (checkPlayerInput(UP, inputs))
            arene.playerShooter.setY(arene.playerShooter.getY() - 1);
        if (checkPlayerInput(LEFT, inputs))
            arene.playerShooter.setX(arene.playerShooter.getX() - 1);
        if (checkPlayerInput(DOWN, inputs))
            arene.playerShooter.setY(arene.playerShooter.getY() + 1);
        if (checkPlayerInput(RIGHT, inputs))
            arene.playerShooter.setX(arene.playerShooter.getX() + 1);
        if (checkPlayerInput(BTN_2, inputs))
            spawnPotato(10);
        if (checkPlayerInput(BTN_4, inputs))
            spawnPeashooter(3);
        if (checkPlayerInput(BTN_1, inputs))
            arene.getBullets().push_back(*arene.playerShooter.shoot());
        if (checkPlayerInput(BTN_3, inputs))
            tremblementDeTerre(charge);

        // Update du random, c'est au tour du directeur
        inputUpdateDirector(inputs);

        generateEnemy();

        arene.update();
        
        std::system("cls");
        arene.display();
        std::cout << arene.playerShooter.health.displayBar();
        std::vector<Enemy> zombieMort;
        for (int i = 0; i < arene.getEnemies().size();) {
            if (arene.getEnemies()[i].getY() == arene.GRID_Y - 1) {
                arene.playerShooter.health.decreaseHealth(9999); // Enemy reached the end, you're dead!
                zombieMort.push_back(arene.getEnemies()[i]);
                arene.deleteEnemy(i);
            }
            else if (arene.getEnemies()[i].getHealth() <= 0) {
                zombieMort.push_back(arene.getEnemies()[i]);
                arene.deleteEnemy(i);
            }
            else {
                i++;
            }

            if (arene.playerShooter.health.getHealth() == 0) {
                loop = false;
                gameOver();
            }
        }

        for (int i = 0; i < arene.getPotatoes().size(); i++) {
            if (arene.getPotatoes()[i].getHealth() <= 0) {
                arene.deletePotato(i);
            }
        }
        for (int i = 0; i < arene.getPeaShooters().size(); i++) {
            if (arene.getPeaShooters()[i].getHealth() <= 0) {
                arene.deletePeaShooter(i);
            }
        }
        
        charge += (int)zombieMort.size();
        zombieMort.clear();
        std::this_thread::sleep_for(250ms);
    }
    
}

// Lecture du JSON et des entrées du clavier
std::vector<GameControls> Gameloop :: readUserInput(json yeet) {
    vector<GameControls> inputs = {};
    char keyboardInput;
    int bouge = yeet.value("mouvement", 0);
    int bouton = yeet.value("Bouton", 0);

    if (bouge == 1)
        inputs.push_back(UP);
    if (bouge == 3)
        inputs.push_back(LEFT);
    if (bouge == 2)
        inputs.push_back(DOWN);
    if (bouge == 4)
        inputs.push_back(RIGHT);
    if (bouton == 2)
        inputs.push_back(BTN_2);
    if (bouton == 4)
        inputs.push_back(BTN_4);
    if (bouton == 1)
        inputs.push_back(BTN_1);
    if (bouton == 3)
        inputs.push_back(BTN_3);

    if (_kbhit())
        keyboardInput = _getch();
    else
        keyboardInput = NONE;
    
    // Check if keyboard input is already in the vector. If not, lets add it.
    inputs.push_back((GameControls)keyboardInput);

    return inputs;
   
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


