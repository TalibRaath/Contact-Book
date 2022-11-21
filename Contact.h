#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
	#include <iostream>
	#include <string>
#endif // !BASIC_LIB

#include "Address.h"


class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address* address;

public:
	bool equals(const Contact& contact);
	Contact* copy_contact();
	Contact();
	Contact(std::string first_name, std::string last_name, std::string mobile_number,
		std::string email_address, Address* address);

	//Setters
	void setFirst_Name(std::string first_name);
	void setLast_Name(std::string last_name);
	void setMobile_Number(std::string mobile_number);
	void setEmail_address(std::string emailemail_address);
	//Setting Adress
	void setAddress(Address add);

	//Getters
	std::string getFirst_Name();
	std::string getLast_Name();
	std::string getMobile_Number();
	std::string getEmail_Address();

	//Address Printing Fucntion
	void AddressPrint();
	//returning address 
	Address* GetAddressObj();
	friend std::istream& operator >>(std::istream& input, Contact& contact);

	void isinputvalid(std::string input, std::string type);
	Contact(Contact& contact);
};