#ifndef BOTTLINGPLANT_H
#define BOTTLINGPLANT_H
class Printer;
class NameServer;
class Truck;

class BottlingPlant {
	Printer &prt;
	NameServer &nameServer;
	unsigned int numVendingMachines;
	unsigned int maxShippedPerFlavour;
	unsigned int maxStockPerFlavour;
	unsigned int timeBetweenShipments;
	Truck *truck;
	unsigned int production[5]; // save for productions
  public:
	//constructor
    BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines,
                 unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour,
                 unsigned int timeBetweenShipments );
    ~BottlingPlant();
    //move the production on the truck
    void getShipment( unsigned int cargo[] );
    //produce product and calls truck to action
    void action();
};
#endif


