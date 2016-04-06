#include "bottlingplant.h"
#include "PRNG.h"
#include "printer.h"
#include "truck.h"
#include <iostream>
using namespace std;
//using prng to generate the amount of bottles it produces
extern PRNG prng;
//constructer of BottlingPlant, initial the array of production and call truck to action
BottlingPlant::BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int nv,
                 unsigned int ms, unsigned int maxStockPerFlavour,
		 unsigned int timeBetweenShipments ):prt(prt),nameServer(nameServer),
    						     numVendingMachines(nv),
						     maxShippedPerFlavour(ms),
    						     maxStockPerFlavour(maxStockPerFlavour),
						     timeBetweenShipments(timeBetweenShipments){
		truck = new Truck(prt,nameServer,*this,numVendingMachines,maxStockPerFlavour); // use for calling a truck
		for(int i = 0; i<5; i++){
		    production[i] = 0;
		}
		prt.print(Printer::BottlingPlant,'S');
		for(int i=0;i<4;i++){
		    production[i]=prng(maxShippedPerFlavour);
		}
		production[4]= production[0]+production[1]+production[2]+production[3];
		prt.print(Printer::BottlingPlant,'G',production[4]);
		truck->action();
}

//destructor and print F
BottlingPlant::~BottlingPlant(){
	prt.print(Printer::BottlingPlant,'F');
	delete truck;
}

//put all the production on the truck
void BottlingPlant::getShipment( unsigned int cargo[] ){
	for(int i = 0;i<5; i++){
		cargo[i] = production[i];
	}
	prt.print(Printer::BottlingPlant,'P');
}

//call the truck to action
void BottlingPlant::action(){
	int temp = prng(4);
	if (temp != 0){
		if(prng(timeBetweenShipments-1) == 0){
			unsigned int totalproduction=0;
			for(int i = 0; i<4;i++){
				unsigned int perflavor = prng(maxShippedPerFlavour);
				production[i] = perflavor;
				totalproduction += perflavor;
			}
			production[4] = totalproduction;
			prt.print(Printer::BottlingPlant,'G',totalproduction);
			truck->action();
		}
	}
	else{
		production[4] = 0;
		prt.print(Printer::BottlingPlant,'X');
		return;
	}
}




