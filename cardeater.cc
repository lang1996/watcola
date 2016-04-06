#include "cardeater.h"
#include "printer.h"
#include "watcard.h"
#include "PRNG.h"
#include <iostream>
//use prng to geerate the chance of destroying a card
extern PRNG prng;
//constructor vendingmachine
VendingMachineCardEater::VendingMachineCardEater( Printer &prt, NameServer &nameServer,
                        unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ):
	VendingMachine(prt,nameServer,id,sodaCost,maxStockPerFlavour ){}

//inherit from vendingmachine
VendingMachine::Status VendingMachineCardEater::buy(Flavours flavour, WATCard *&card ){
	Status which;
	if(stock[flavour] == 0){//vendingmachine does not have enough bottle for that flavour
		if(prng(9)==0){
		delete card;
		card=NULL;
	}
		which=STOCK;
	}
	else if(card->getmoney() < sodaCost){//the student does not have enough money
	if(prng(9)==0){
		delete card;
		card=NULL;
	}
		which= FUNDS;
	}
	else{//buy successfully		
		stock[flavour]--;
		prt.print(Printer::Vending,id,'B',flavour,stock[flavour]);
		card->pay(sodaCost);
		if(prng(9)==0){
		delete card;
		card=NULL;
		}
		which = BUY;
	}
	return which;
}


