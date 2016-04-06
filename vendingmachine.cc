#include "vendingmachine.h"
#include "printer.h"
#include "nameserver.h"
#include "watcard.h"
#include "PRNG.h"

VendingMachine::VendingMachine( Printer &prt, NameServer &nameServer,
	unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ):prt(prt),
	nameServer(nameServer),id(id),sodaCost(sodaCost),maxStockPerFlavour(maxStockPerFlavour){
		for(int i = 0; i < 4; i++){
			stock[i] = 0;
		}
		prt.print(Printer::Vending,id,'S',sodaCost);
		nameServer.VMregister(this);
	}

VendingMachine::~VendingMachine(){
	prt.print(Printer::Vending,id,'F');
}        // necessary to trigger destructors in inherited classes

VendingMachine::Status VendingMachine::buy(Flavours flavour, WATCard *&card ){
	if(stock[flavour] == 0) return STOCK;
	else if(card->getmoney() < sodaCost) return FUNDS;
	else{
		stock[flavour]--;
		prt.print(Printer::Vending,id,'B',flavour,stock[flavour]);
		card->pay(sodaCost);
		return BUY;
	}
}

unsigned int VendingMachine::cost(){
	return sodaCost;
}

unsigned int VendingMachine::getId(){
	return id;
}

unsigned int *VendingMachine::inventory(){
	prt.print(Printer::Vending,id,'r');
	return stock;
}

void VendingMachine::restocked(){
	prt.print(Printer::Vending,id,'R');
}



