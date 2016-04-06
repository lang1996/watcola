#ifndef WATCARDOFFICE_H
#define WATCARDOFFICE_H
//forward declaration
class Printer;
class WATCard;

class WATCardOffice {
    Printer &prt;
  public:
    WATCardOffice( Printer &prt );
    ~WATCardOffice();
    WATCard *create( unsigned int sid, unsigned int amount );
    void transfer( unsigned int sid, unsigned int amount, WATCard &card );
};
#endif



