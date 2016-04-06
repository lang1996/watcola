#ifndef WATCARD_H
#define WATCARD_H

class WATCard {
	unsigned int money;
  public:
  	WATCard();
   	unsigned int getmoney();//return money
  	void pay(unsigned int);//reduce money
  	void add(unsigned int);//add money
};
#endif




