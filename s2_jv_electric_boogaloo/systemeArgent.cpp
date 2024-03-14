#include "systemeArgent.h"


//initialiser l'argent a zero
systemeArgent::systemeArgent() : money(0) {}; 

//regarder si un zombie est mort et ajouter argent
void systemeArgent::killZombie() {
	money += 10;
}

//regarder si on a l'argent pour acheter pea shooter
bool systemeArgent::checkFundsPeaShooter() {
	return money >= 20;
}

//regarder si on a l'argent pour acheter patate
bool systemeArgent::checkFundsPotato() {
	return money >= 30;
}

//acheter pea shooter et enlever argent
void systemeArgent::buyPeaShooter() {
	money -= 20;
}

//acheter patate et enlever argent
void systemeArgent::buyPotato() {
	money -= 30;
}

//regarder le montant d'argent qu'on a
int systemeArgent::checkMoney() {
	return money;
}