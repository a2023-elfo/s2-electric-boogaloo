/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
*/

/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include <LiquidCrystal.h>

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 9600        // Frequence de transmission serielle
const int rs = 22, en = 24, d4 = 26, d5 = 28, d6 = 30, d7 = 32;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message

//LED
int pinLED1 = 42;
int pinLED2 = 40;
int pinLED3 = 38;
int pinLED4 = 36;

//JOYSTICK
int pinjoy_X= A15;
int pinjoy_Y= A14;

//BOUTONS
int SW1 = 29;
int SW2 = 23;
int SW3 = 31;//PASOK
int SW4 = 27;
int SW5 = 53;
int SW6 = 0;

//BARGRAPH
int bar1 = 51;
int bar2 = 49;
int bar3 = 47;
int bar4 = 45;
int bar5 = 43;
int bar6 = 41;
int bar7 = 33;
int bar8 = 35;
int bar9 = 37;
int bar10 = 39;

int bouton = 0 ;
int mouvement = 0;
int joy_X_Value = 0;
int joy_Y_Value = 0;

/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(); 
void readMsg();
void serialEvent();

/*---------------------------- Fonctions "Main" -----------------------------*/

void setup() {
  Serial.begin(BAUD); // Initialisation de la communication serielle
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinLED4, OUTPUT);
  pinMode(bar1, OUTPUT);
  pinMode(bar2, OUTPUT);
  pinMode(bar3, OUTPUT);
  pinMode(bar4, OUTPUT);
  pinMode(bar5, OUTPUT);
  pinMode(bar6, OUTPUT);
  pinMode(bar7, OUTPUT);
  pinMode(bar8, OUTPUT);
  pinMode(bar9, OUTPUT);
  pinMode(bar10, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Lien Arduino-PC");
}

/* Boucle principale (infinie) */
void loop() {
  joy_X_Value = analogRead(pinjoy_X);
  joy_Y_Value = analogRead(pinjoy_Y);
  mouvement = 0;
  bouton = 0;

  if (joy_Y_Value < 100)
    mouvement = 1;
  else if (joy_Y_Value > 1000)
    mouvement = 2;
  else if (joy_X_Value < 100)
    mouvement = 3;
  else if (joy_X_Value > 1000)
    mouvement = 4;
  
  if (digitalRead(SW1) == LOW)
    bouton = 1;
  if (digitalRead(SW2) == LOW)
    bouton = 2;
  //if (digitalRead(SW3) == LOW)
    //bouton = 3;
  if (digitalRead(SW4) == LOW)
    bouton = 4;
  if (digitalRead(SW5) == LOW)
    bouton = 5;
  
  if (shouldRead_) 
  {
    readMsg();
    sendMsg();
  }

  delay(10);
}

/*---------------------------Definition de fonctions ------------------------*/

void serialEvent() { shouldRead_ = true; }


/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void sendMsg() {
  StaticJsonDocument<500> doc;
  // Elements du message
  doc["time"] = millis();
  doc["mouvement"] = mouvement;
  doc["Bouton"] = bouton;

  // Serialisation
  serializeJson(doc, Serial);

  // Envoie
  Serial.println();
  shouldSend_ = false;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
void readMsg(){
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;

  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(doc, Serial);
  shouldRead_ = false;

  // Si erreur dans le message
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  // Analyse des éléments du message
  parse_msg = doc["Affichage"];
  
  if (!parse_msg.isNull()) {
    lcd.clear();
    lcd.setCursor(0,1);  
    lcd.print(parse_msg.as<String>());
  }
}

