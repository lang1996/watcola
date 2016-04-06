#include "overcharge.h"
#include "printer.h"
#include "watcard.h"

VendingMachineOverCharger::VendingMachineOverCharger( Printer &prt, NameServer &nameServer,
                        unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ):
	VendingMachine(prt,nameServer,id,2*sodaCost,maxStockPerFlavour){}

VendingMachine::Status VendingMachineOverCharger::buy(Flavours flavour, WATCard *&card ){
	if(stock[flavour] == 0) return STOCK;
	else if(card->getmoney() < sodaCost) return FUNDS;
	else{
		stock[flavour]--;
		prt.print(Printer::Vending,id,'B',flavour,stock[flavour]);
		card->pay(sodaCost);
		return  BUY;
	}
}




