#include "nameserver.h"
#include "vendingmachine.h"
#include <iostream>
#include "printer.h"

using namespace std;
//the constructor of nameserver
NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents ):prt(prt),
numVendingMachines(numVendingMachines),numStudents(numStudents),index(0),whichv(0){
	machines = new VendingMachine *[numVendingMachines];
	prt.print(Printer::NameServer,'S');
}

//destructor, delete machine
NameServer::~NameServer(){
	delete [] machines;
	pairs.clear();
	prt.print(Printer::NameServer,'F');
}

//register machines 
void NameServer::VMregister( VendingMachine *vendingmachine ){
	machines[index] = vendingmachine;
	index++;
	prt.print(Printer::NameServer,'R',vendingmachine->getId());
}

//get all machine corresponding the machine students points at
VendingMachine * NameServer::getMachine( unsigned int id ){
	if(pairs.size()<numStudents){//initial 
		if(whichv == numVendingMachines) whichv = 0;
		pair<unsigned int, VendingMachine*>tmp;
		tmp = make_pair(id,machines[whichv]);
		pairs.push_back(tmp);
		prt.print(Printer::NameServer,'N',id,pairs.at(whichv).second->getId());
		whichv++;
		return machines[whichv-1];
	}
	unsigned int location = 0;
	VendingMachine *cv;
	for(;location < numStudents ; location++){//find that student locatoin in vector
		if(pairs.at(location).first == id){
			cv = pairs.at(location).second;
			break;
		}
	}
	unsigned int cvmindex= 0;//find the location of that specific machine
	for(; cvmindex<numVendingMachines; cvmindex++){
		if(machines[cvmindex] == cv) break;
	}
	if(cvmindex == numVendingMachines-1) pairs.at(location).second = machines[0];
	else pairs.at(location).second = machines[cvmindex+1];
	prt.print(Printer::NameServer,'N',id,pairs.at(location).second->getId());

	return pairs.at(location).second;
}

//get machine list
VendingMachine ** NameServer::getMachineList(){
	return machines;
}




