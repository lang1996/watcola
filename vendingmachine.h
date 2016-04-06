#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
//forward declaration
class Printer;
class NameServer;
class WATCard;

class VendingMachine {                // general vending machine
    protected:
        Printer &prt;
        NameServer &nameServer;
        unsigned int id;
        unsigned int sodaCost;
        unsigned int maxStockPerFlavour;
        unsigned int stock[4];//stock the production
  public:
    enum Status { BUY, STOCK, FUNDS }; // purchase status: successful buy, out of stock, insufficient funds
    enum Flavours { BBC, CC, RRB, JL };
    VendingMachine( Printer &prt, NameServer &nameServer,
                        unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    virtual ~VendingMachine();        // necessary to trigger destructors in inherited classes
    virtual Status buy(Flavours flavour, WATCard *&card ); // YOU DEFINE FLAVOURS
    virtual unsigned int cost();
    virtual unsigned int getId();
    virtual unsigned int *inventory();
    virtual void restocked();
};
#endif



