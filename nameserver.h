#ifndef NAMESERVER_H
#define NAMESERVER_H
#include <vector>
#include <utility>
//forward declaration
class VendingMachine;
class Printer;
//manage the vending-machines names
class NameServer {
	Printer &prt;
	unsigned int numVendingMachines;
	unsigned int numStudents;
	int index;
	unsigned int whichv;
	VendingMachine ** machines;
	std::vector< std::pair<unsigned int, VendingMachine *> > pairs;
  public:
    NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
    ~NameServer();
    //register the machines
    void VMregister( VendingMachine *vendingmachine );
    //find the corresponging machine to each students
    VendingMachine *getMachine( unsigned int id );
    //get the list of machines
    VendingMachine **getMachineList();
};
#endif


