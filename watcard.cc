#include "watcard.h"

WATCard::WATCard():money(5){}

unsigned int WATCard::getmoney(){
	return money;
}

void WATCard::pay(unsigned int change){
	money -= change;
}

void WATCard::add(unsigned int addmoney){
	money += addmoney; 
}



