#include "systemeArgent.h"


//initialiser l'argent a zero
systemeArgent::systemeArgent(){
	money = 0;
} 

//regarder si un zombie est mort et ajouter argent
void systemeArgent::killZombie() {
	money += 10;
	emit moneyUpdated(money);
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
	if (checkFundsPeaShooter()) {
		money -= 20;
		std::cout << "Pea Shooter achete!!";
	}
	else {
		std::cout << "Smells like broke\n";
	}
	emit moneyUpdated(money);
}

//acheter patate et enlever argent
void systemeArgent::buyPotato() {
	if (checkFundsPotato()) {
		money -= 30;
		std::cout << "Patate achete!!";
	}
	else {
		std::cout << "Smells like broke\n";
	}
	emit moneyUpdated(money);
}

//regarder le montant d'argent qu'on a
int systemeArgent::checkMoney() {
	return money;
}

int systemeArgent::getMoney() const {
	return money;
}