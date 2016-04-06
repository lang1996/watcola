class Student {
  public:
    struct Finished {};            // exception raised on completion
    Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id,
             unsigned int maxPurchases );
    void action();
};


class WATCard {
  public:
    // you design a general WATCard
};


class WATCardOffice {
  public:
    WATCardOffice( Printer &prt );
    WATCard *create( unsigned int sid, unsigned int amount );
    void transfer( unsigned int sid, unsigned int amount, WATCard &card );
};


class VendingMachine {                // general vending machine
  public:
    enum Status { BUY, STOCK, FUNDS }; // purchase status: successful buy, out of stock, insufficient funds
    VendingMachine( Printer &prt, NameServer &nameServer,
                        unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    virtual ~VendingMachine();        // necessary to trigger destructors in inherited classes
    virtual Status buy( Flavours flavour, WATCard *&card ); // YOU DEFINE FLAVOURS
    virtual unsigned int cost();
    virtual unsigned int getId();
    virtual unsigned int *inventory();
    virtual void restocked();
};

class VendingMachineCardEater : public VendingMachine { // specific vending machine
  public:
    VendingMachineCardEater( Printer &prt, NameServer &nameServer,
                        unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    // member routines from VendingMachine
};

class VendingMachineOverCharger : public VendingMachine { // specific vending machine
  public:
    VendingMachineOverCharger( Printer &prt, NameServer &nameServer,
                        unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    // member routines from VendingMachine
};


class NameServer {
  public:
    NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
    void VMregister( VendingMachine *vendingmachine );
    VendingMachine *getMachine( unsigned int id );
    VendingMachine **getMachineList();
};


class BottlingPlant {
  public:
    BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines,
                 unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour,
                 unsigned int timeBetweenShipments );
    void getShipment( unsigned int cargo[] );
    void action();
};


class Truck {
  public:
    Truck( Printer &prt, NameServer &nameServer, BottlingPlant &plant,
           unsigned int numVendingMachines, unsigned int maxStockPerFlavour );
    void action();
};


class Printer {
    struct PrinterImpl;
    PrinterImpl &impl;
  public:
    enum Kind { WATCardOffice, NameServer, Truck, BottlingPlant, Student, Vending };
    Printer( unsigned int numStudents, unsigned int numVendingMachines );
    ~Printer();
    void print( Kind kind, char state );
    void print( Kind kind, char state, int value1 );
    void print( Kind kind, char state, int value1, int value2 );
    void print( Kind kind, unsigned int lid, char state );
    void print( Kind kind, unsigned int lid, char state, int value1 );
    void print( Kind kind, unsigned int lid, char state, int value1, int value2 );
};
