#ifndef VENDINGMACHINEOVERCHARGER_H
#define VENDINGMACHINEOVERCHARGER_H
#include "vendingmachine.h"
//forward declaration
class Printer;
class NameServer;

//VendingMachineOverCharger is a sub class of vendingmachine
class VendingMachineOverCharger : public VendingMachine { // specific vending machine
  public:
    //the cost is double from original cost
    VendingMachineOverCharger( Printer &prt, NameServer &nameServer,
                        unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    VendingMachine::Status buy(Flavours flavours, WATCard *&card);
    // member routines from VendingMachine
};
#endif

