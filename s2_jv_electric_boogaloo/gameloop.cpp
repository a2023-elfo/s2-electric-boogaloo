#include "gameloop.h"

using json = nlohmann::json;

/*------------------------------ Constantes ---------------------------------*/
#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message

/*------------------------- Prototypes de fonctions -------------------------*/
bool SendToSerial(SerialPort* arduino, json j_msg);
bool RcvFromSerial(SerialPort* arduino, std::string& msg);

SerialPort* arduino; //doit etre un objet global!!!!


void Gameloop::gameOver(){
    std::system("cls");
    std::cout << "GAME OVER" << std::endl;
    std::cout << "Score : " << arene->nbEnemyKilled << std::endl;
    emit gameOverSignal(arene->nbEnemyKilled); // Émettre le signal avec le score
    emit changepage(GAMEOVER_SCREEN);
}

Gameloop::Gameloop() {
    argent = new systemeArgent();
    arene = new Grid();
}

void Gameloop::setupDirector() {
    // Set base of random, current time
    // For debug, replace director random for a known value and the same result will happen every time
    auto currentTime = std::chrono::system_clock::now().time_since_epoch();
    directorRandom = std::chrono::duration_cast<std::chrono::seconds>(currentTime).count();
}

void Gameloop::inputUpdateDirector(std::vector<GameControls>& inputVect) {
    directorRandom++;
    for (int i = 0; i < inputVect.size(); i++) {
        directorRandom += (long)inputVect.at(i);
    }
}

// Generate a value between min (included) and max (excluded)
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

void Gameloop::reset()
{
    delete(arene);
    arene = new Grid();
    charge = 0;
    directorFunds = 0;
    loop = true;
}

void Gameloop::generateEnemy() {
    // Add funds for trying to generate
    directorFunds += generateValue(1, 20);

    // Try to generate enemy if sufficient funds
    // Lower the max value of the generation to increase chance of spawn. Could be difficulty curve with time.
    if (directorFunds + arene->nbEnemyKilled >= NORMAL && generateValue(1, 10) == 1) { // Enough funds. If we get more types, this algorithm will have to change
        
        // Remove funds, even if we don't spawn. Prevents overpopulation
        directorFunds -= NORMAL;

        // We are spawning an enemy, choose position
        int desiredPosition = generateValue(0, arene->GRID_X);
        int bossHealth = 10 + arene->nbEnemyKilled / 7;
        int enemyHealth = 5 + arene->nbEnemyKilled / 10;
        if (bossHealth > 20) {
            bossHealth = 20;
        }
        if (enemyHealth > 12) {
            enemyHealth = 12;
        }

        if (arene->grille[desiredPosition][0] == ' ' || arene->grille[desiredPosition][0] == 'B') {  // Empty, we can spawn
            
            int spawnRock = generateValue(1, 100);
            if (spawnRock <= arene->nbEnemyKilled) {
                Enemy zombie(bossHealth, desiredPosition, 'W');
                arene->getEnemies().push_back(zombie);
            }
            else {
                Enemy zombie(enemyHealth, desiredPosition, 'X');
                arene->getEnemies().push_back(zombie);
            }
        }
    }
}

bool Gameloop::checkPlayerInput(GameControls checkedInput, std::vector<GameControls>& inputVect) {
    return std::find(inputVect.begin(), inputVect.end(), checkedInput) != inputVect.end();
}

void Gameloop::mainLoop() {
    char userInput;
    argent =new systemeArgent();
    loop = true;
    charge = 1;
    arene->display();
    bool usecharge = false;

    std::string raw_msg;

    //Struct. Donn�es JSON 
    int bouge = 0;
    int bouton = 0;

    // Initialisation du port de communication
    bool keyboardOnly = this->com == "ELFO";

    arduino = new SerialPort(com.c_str(), BAUD);

    if (!arduino->isConnected() && !keyboardOnly) {
        std::cerr << "Impossible de se connecter au port " << std::string(this->com) << ". Fermeture du programme!" << std::endl;
        exit(1);
    }
    else {
        std::cout << "Connexion OK " << std::endl;
    }
    
    // Structure de donnees JSON pour envoie et reception
    json j_msg_send, j_msg_rcv;
    std::vector<GameControls> inputs;

    while (loop) {

       
        // Envoie message Arduino
        j_msg_send["Affichage"] = "Mouvement=" + std::to_string(bouge) + " B=" + std::to_string(bouton);
        j_msg_send["vie"] = arene->playerShooter.health.getHealth();
        j_msg_send["charge"] = charge;
        if (!keyboardOnly) {
            if (!SendToSerial(arduino, j_msg_send)) {
                std::cerr << "Erreur lors de l'envoie du message. " << std::endl;
            }

          // Reception message Arduino
            if (!RcvFromSerial(arduino, raw_msg)) {
                std::cerr << "Erreur lors de la reception du message. " << std::endl;
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
        char positionPlant = arene->grille[arene->playerShooter.getX()][arene->playerShooter.getY() - 1];

        if (checkPlayerInput(UP, inputs))
            arene->playerShooter.setY(arene->playerShooter.getY() - 1);
        if (checkPlayerInput(LEFT, inputs))
            arene->playerShooter.setX(arene->playerShooter.getX() - 1);
        if (checkPlayerInput(DOWN, inputs))
            arene->playerShooter.setY(arene->playerShooter.getY() + 1);
        if (checkPlayerInput(RIGHT, inputs))
            arene->playerShooter.setX(arene->playerShooter.getX() + 1);
        if (checkPlayerInput(BTN_2, inputs))
            if (positionPlant != 'P' && positionPlant != 'O') {
                if (argent->checkFundsPotato()) {
                    argent->buyPotato();
                    spawnPotato(5);
                }
            }
        if (checkPlayerInput(BTN_4, inputs)){
            if (positionPlant != 'P' && positionPlant != 'O') {
                if (argent->checkFundsPeaShooter()) {
                    argent->buyPeaShooter();
                    spawnPeashooter(1);
                }
            }
        }
        
        if (checkPlayerInput(BTN_6, inputs))
            arene->getBullets().push_back(*arene->playerShooter.shoot());
        if (checkPlayerInput(ACCELERO, inputs))
            activerTremblementDeTerre(&charge, &usecharge);

        // Update du random, c'est au tour du directeur
        inputUpdateDirector(inputs);

        generateEnemy();

        arene->update();
        
        std::system("cls"); 
      
        arene->display();
        
        emit healthUpdateGL(arene->getHealthPlayer());
        emit superUpdateGL(charge);
        emit moneyUpdated(argent->checkMoney());
        emit sendVectors(arene->getEnemies(), arene->getPeaShooters(), arene->getPotatoes(), arene->getBullets(), arene->playerShooter);


        std::cout << arene->playerShooter.health.displayBar() << std::endl << std::endl;
        std::cout << "Current money: " << argent->checkMoney() << std::endl;

        afficherTremblementDeTerre(&charge);

        std::vector<Enemy> zombieMort;
        for (int i = 0; i < arene->getEnemies().size();) {
            if (arene->getEnemies()[i].getY() == arene->GRID_Y - 1) {
                arene->playerShooter.health.decreaseHealth(9999); // Enemy reached the end, you're dead!
                zombieMort.push_back(arene->getEnemies()[i]);
                arene->deleteEnemy(i);
            }

            else if (arene->getEnemies()[i].getHealth() <= 0) {
                zombieMort.push_back(arene->getEnemies()[i]);
                arene->deleteEnemy(i);
                arene->nbEnemyKilled++;
                argent->killZombie(); //ajouter argent quand zombie est mort
            }
            else {
                i++;
            }

            if (arene->playerShooter.health.getHealth() == 0) {
                loop = false;
                j_msg_send["vie"] = arene->playerShooter.health.getHealth();
                SendToSerial(arduino, j_msg_send);
                gameOver();
            }
        }

        for (int i = 0; i < arene->getPotatoes().size(); i++) {
            if (arene->getPotatoes()[i].getHealth() <= 0) {
                arene->deletePotato(i);
            }
        }
        for (int i = 0; i < arene->getPeaShooters().size(); i++) {
            if (arene->getPeaShooters()[i].getHealth() <= 0) {
                arene->deletePeaShooter(i);
            }
        }
        if (!usecharge) {
            charge += (int)zombieMort.size();
            if (charge > 10) {
                charge = 10;
            }
        }
        else {
            usecharge = false;
        }
        zombieMort.clear();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        
    }
}

// Lecture du JSON et des entrées du clavier
std::vector<GameControls> Gameloop :: readUserInput(json yeet) {
    std::vector<GameControls> inputs = {};
    char keyboardInput = NONE;
    int bouge = yeet.value("mouvement", 0);
    int bouton = yeet.value("Bouton", 0);
    bool tbt = yeet.value("pouvoir", 0);
    // Lecture de la manette
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
    if (bouton == 5)
        inputs.push_back(BTN_5);
    if (bouton == 6)
        inputs.push_back(BTN_6);
    if (tbt)
        inputs.push_back(ACCELERO);

    // CRead keyboard input. All values that are not valid are still used to offset directorRandom, so we keep em
    while (_kbhit()) {
        keyboardInput = _getch();
        inputs.push_back((GameControls)keyboardInput);
    }

    return inputs;
}

void Gameloop :: spawnPeashooter(int health) {
    
    PeaShooter piouPiou(health, arene->playerShooter.getX(), arene->playerShooter.getY() - 1);
    arene->getPeaShooters().push_back(piouPiou);
}
void Gameloop :: spawnPotato(int health) {
    Potato bigMama(health, arene->playerShooter.getX(), arene->playerShooter.getY() - 1);
    arene->getPotatoes().push_back(bigMama);

}
void Gameloop:: afficherTremblementDeTerre(int* charge) {
    const int maxCharge = 10; // Charge maximale pour le super

   // Toujours afficher la barre de chargement en bas de la grille
    std::cout << "Super: [";

     // Afficher les barres de chargement en remplaçant les | par des X
    for (int i = 0; i < maxCharge; ++i) {
        if (i < *charge) {
            std::cout << "O";
        } else {
            std::cout << "-";
        }
    }
    std::cout << "]" << std::endl;
}
void Gameloop::activerTremblementDeTerre(int* charge, bool* usecharge) {

    // Si la barre est pleine de X, la charge est suffisante pour utiliser le super
    if (*charge >= 10) {
        // tremblement de terre active
        for (int i = 0; i < arene->getEnemies().size(); i++) {
            arene->getEnemy(i)->decreaseHealth(999);
        }
        std::cout << "Tous les ennemis ont ete elimines par le tremblement de terre!" << std::endl;
        *charge = 0;
        *usecharge = true;
    }
    else {
        std::cout << "La charge du tremblement de terre est insuffisante." << std::endl;
    }
}
void Gameloop::recupPortDeComTitleScreen(QString portDecom) {
    this->com= portDecom.toStdString();
    qInfo() <<"le port est" << portDecom;
}

/*---------------------------Definition de fonctions JSON------------------------*/
bool SendToSerial(SerialPort* arduino, json j_msg) {
    // Return 0 if error
    std::string msg = j_msg.dump();
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}

bool RcvFromSerial(SerialPort* arduino, std::string& msg) {
    // Return 0 if error
    // Message output in msg
    std::string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear string
// Version fonctionnelle dans VScode et Visual Studio
    buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);
    return true;
}
