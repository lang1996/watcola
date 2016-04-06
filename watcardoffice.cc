#include "watcardoffice.h"
#include "PRNG.h"
#include "printer.h"
#include "watcard.h"
.//generate the possibility of get half money
extern PRNG prng;

WATCardOffice::WATCardOffice( Printer &prt ):prt(prt){
	prt.print(Printer::WATCardOffice,'S');
}

WATCardOffice::~WATCardOffice(){
	prt.print(Printer::WATCardOffice,'F');
}

WATCard * WATCardOffice::create( unsigned int sid, unsigned int amount ){
	WATCard * newwatcard = new WATCard();//create a new card
	prt.print(Printer::WATCardOffice,'C',sid,amount);
	return newwatcard;
}
void WATCardOffice::transfer( unsigned int sid, unsigned int amount, WATCard &card ){
	prt.print(Printer::WATCardOffice,'t',sid,amount);
	if(prng(3) == 0){// get half money
	amount = amount / 2;
	}
	card.add(amount);
	prt.print(Printer::WATCardOffice,'T',sid,amount);
}





