#ifndef __CashRegister_H__
#define __CashRegister_H__

#include <iostream>

class CashRegister {
public: // public: functions and variables that are available to any part of the program
	CashRegister() : contents(0) {}  // default constructor: allows us to create the object
	CashRegister(const CashRegister &rhs) : contents(rhs.contents) {} // copy constructor: create an object by copying another
	
	void run();  

private: // private: only objects that are of type CashRegister can access these functions/variables
	double contents; // refers to the money in the cash register
	
	void addMoney(float amount); // add money to the cash register	
	void removeMoney(float amount); // remove money from the cash register
};

#endif // __CashRegister_H__
