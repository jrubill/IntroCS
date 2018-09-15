#include "CashRegister.h"

/* 
	The reason why we put the name of the class before each function is because this is how we deal with
	the "scope" of the function. For example, if one class has a method called delete, and the one we're 
	working with has a function called delete, which one gets called? We deal with this by using the scope 
	operator. 
*/

void CashRegister::addMoney(float amount) { contents += amount; }

void CashRegister::removeMoney(float amount) { contents -= amount; }

void CashRegister::run() {
	// set up our buffer
	std::string buffer;
	std::cout << "supported commands are (help, add, remove, contents)" << std::endl;
	std::cout << "Register> ";
	std::getline(std::cin, buffer);	

	// while they don't type quit, keep looking for input
	while (buffer.compare("quit") != 0) {	
	
		if (buffer.compare("help") == 0) { // if the buffer IS 'help'
			std::cout << "(help, add, remove, contents)" << std::endl;
		}
		
		
		else if (buffer.find("add") != std::string::npos) { // if the buffer contains the word 'add'
			addMoney(std::stof(buffer.substr(buffer.find(" ")+1)));	
		}
		
		
		else if (buffer.find("remove") != std::string::npos) { // if the buffer contains the word 'remove'
			removeMoney(std::stof(buffer.substr(buffer.find(" ")+1)));
		}
		
		
		else if(buffer.compare("contents") == 0) { // if the buffer IS 'contents'
			std::cout << "Contents: " << contents << std::endl;
		}
		
		
		else {
			std::cout << "Invalid Command" << std::endl;
		}
		
		std::cout << "Register> ";
		std::getline(std::cin, buffer);
	}
}
