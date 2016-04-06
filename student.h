#ifndef STUDENT_H
#define	STUDENT_H
#include "vendingmachine.h"
#include "cardeater.h"
#include "overcharge.h"
//forward declaration
class Printer;
class NameServer;
class WATCardOffice;
class WATCard;

class Student {
	Printer &prt;
	NameServer &nameServer;
	WATCardOffice &cardOffice;
	unsigned int id; //student id
	unsigned int maxPurchases;
	VendingMachine::Flavours f;//flavour students wants to purchace
	int numbertobuy;// number of items to buy
	WATCard *newcard;//creat a new card
	VendingMachine * corespondingV;// a pointer to a machine
  public:
    struct Finished {};            // exception raised on completion
    Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id,
             unsigned int maxPurchases );
    void action();
};
#endif




