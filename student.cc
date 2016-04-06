#include "student.h"
#include "PRNG.h"
#include "printer.h"
#include "watcardoffice.h"
#include "nameserver.h"
#include "vendingmachine.h"
#include "watcard.h"
#include <iostream>
#include <unistd.h>
using namespace std;
//use to generate a flavour
extern PRNG prng;
//find the machine 
Student::Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id,
        unsigned int maxPurchases):prt(prt),nameServer(nameServer),cardOffice(cardOffice),id(id),
        maxPurchases(maxPurchases){
             numbertobuy = prng(1,maxPurchases);//generate the amount of that flavour
             int favorite = prng(3);//the flavor students to buy
		     if(favorite == 0) f = VendingMachine::BBC;
		     if(favorite == 1) f = VendingMachine::CC;
		     if(favorite == 2) f = VendingMachine::RRB;
		     if(favorite == 3) f = VendingMachine::JL;
             newcard = cardOffice.create(id,5);
             prt.print(Printer::Student,id,'S',favorite,numbertobuy);
             corespondingV = nameServer.getMachine(id);//find the corresponding machine
             prt.print(Printer::Student,id,'V',corespondingV->getId());           	
}

void Student::action(){
	if (numbertobuy == 0){
		delete newcard;
			prt.print(Printer::Student,id,'F');
			throw Finished();
	}
	VendingMachine::Status Which=corespondingV->buy(f,newcard);
	if(newcard == 0){
		prt.print(Printer::Student,id,'D');
		newcard = cardOffice.create(id,5);
	}
	if(Which == VendingMachine::BUY){
		numbertobuy--;
		prt.print(Printer::Student,id,'B',newcard->getmoney());
		return;
		
	}
	else if(Which == VendingMachine::STOCK){
		corespondingV = nameServer.getMachine(id);
		prt.print(Printer::Student,id,'V',corespondingV->getId());
		return;
	}
	else{
		unsigned int addmoney = 5+corespondingV->cost();
		prt.print(Printer::Student,id,'t',addmoney);	
		cardOffice.transfer(id,addmoney,*newcard);
		prt.print(Printer::Student,id,'T',newcard->getmoney());
		return;
	}
}




