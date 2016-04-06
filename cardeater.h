#ifndef VENDINGMACHINECARDEATER_H
#define VENDINGMACHINECARDEATER_H
#include "vendingmachine.h"

//forward declaration 
class Printer;
class NameServer;
//VendingMachineCardeater is a sub class of vendingmachine
class VendingMachineCardEater : public VendingMachine { // specific vending machine
  public:
    VendingMachineCardEater( Printer &prt, NameServer &nameServer,
                        unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    //mutate the implementation of buy
    VendingMachine::Status buy(Flavours flavour, WATCard *&card );

};

#endif



