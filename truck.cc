#include "truck.h"
#include "printer.h"
#include "nameserver.h"
#include "vendingmachine.h"
#include "bottlingplant.h"

Truck::Truck( Printer &prt, NameServer &nameServer, BottlingPlant &plant,
           unsigned int numVendingMachines, unsigned int maxStockPerFlavour ):
	prt(prt),nameServer(nameServer),plant(plant),numVendingMachines(numVendingMachines),
	maxStockPerFlavour(maxStockPerFlavour){
	for(int i = 0; i<4;i++){//initial all the value in cargo
		shipping[i] = 0;
	}
	prt.print(Printer::Truck,'S');
}

Truck::~Truck(){
	prt.print(Printer::Truck,'F');
}

void Truck::action(){
	plant.getShipment(shipping);
	prt.print(Printer::Truck,'P',shipping[4]);
	unsigned int unfilled=0;
	for(unsigned int i = 0; i<numVendingMachines; i++){
		if(shipping[4] == 0) break; // if no production need to ship
		VendingMachine * currentv = nameServer.getMachineList()[i];
		unsigned int *stocks = currentv->inventory();//print r
		prt.print(Printer::Truck,'d',currentv->getId(),shipping[4]);	
		for(int index = 0; index < 4; index++){
			while(stocks[index] < maxStockPerFlavour){
				if(shipping[index] == 0) break;
				stocks[index]++;
				shipping[index]--;
				shipping[4]--;
			}
			if(stocks[index] < maxStockPerFlavour) {//count the amount of unfiled flavour
				unfilled += (maxStockPerFlavour - stocks[index]);
			}
		}
		if(unfilled != 0){
			prt.print(Printer::Truck,'U',currentv->getId(),unfilled);
		}
		prt.print(Printer::Truck,'D',currentv->getId(),shipping[4]);
		currentv->restocked();
		unfilled = 0;//reset unfilled for next vendingmacine
	}
}






