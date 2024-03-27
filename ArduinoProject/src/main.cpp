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
int del[4] = {pinLED1, pinLED2, pinLED3, pinLED4};
//JOYSTICK
int pinjoy_X= A15;
int pinjoy_Y= A14;

//BOUTONS
int SW1 = 29;
int SW2 = 23;
int SW3 = 31;//PASOK
int SW4 = 27;
int SW5 = 53;
int SW6 = 25;

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
int bargraph[10] = {bar1, bar2, bar3, bar4, bar5, bar6, bar7, bar8, bar9, bar10};

int bouton = 0 ;
int mouvement = 0;
int joy_X_Value = 0;
int joy_Y_Value = 0;
int vie = 10;
int nb_power = 0;
bool pouvoir = false;
float charge = 0;
float total_charge = 4.0;
float result = 0.0;
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
  for (int i = 0; i < vie; i++)
  {
    digitalWrite(bargraph[i], HIGH);
  }
}

/* Boucle principale (infinie) */
void loop() {
  joy_X_Value = analogRead(pinjoy_X);
  joy_Y_Value = analogRead(pinjoy_Y);
  mouvement = 0;
  bouton = 0;
  pouvoir = false;

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
  if (digitalRead(SW3) == LOW)
    bouton = 3;
  if (digitalRead(SW4) == LOW)
    bouton = 4;
  if (digitalRead(SW5) == LOW)
    bouton = 5;
  if (digitalRead(SW6) == LOW)
    bouton = 6;

  if (analogRead(A3) > 350)
    pouvoir = true;

  if (shouldRead_) 
  {
    readMsg();
    sendMsg();
  }

  if (nb_power > 0)
    pouvoir = true; //Si shake manette
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
  doc["pouvoir"] = pouvoir;
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
    //lcd.print(parse_msg.as<String>());
  }

  vie = doc["vie"];
  for (int i = vie; i < 10; i++)
  {
    digitalWrite(bargraph[i], LOW);
  }

  nb_power = doc["nbpower"];
  for (int i = 0; i < nb_power; i++)
  {
    digitalWrite(del[i], HIGH);
  }

  charge = doc["charge"];
  result = charge / total_charge;
  lcd.print(result);
  if (result >= 0.25 && result < 0.5) {
    digitalWrite(pinLED4, HIGH);
  }
  else if (result >= 0.5 && result < 0.75) {
    digitalWrite(pinLED3, HIGH);
  }
  else if (result >= 0.75 && result < 1) {
    digitalWrite(pinLED2, HIGH);
  }
  else if (result == 1) {
    digitalWrite(pinLED1, HIGH);
  }
  else {
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, LOW);
    digitalWrite(pinLED4, LOW);
  }
}

