#pragma once
#include <iostream>
#include <string>

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	Address();
	 
	bool equals(const Address& address);
	void print_address();
	Address *copy_address();

	Address(std::string house, std::string street, std::string city, std::string country);
	//Setters
	void sethouse(std::string h);
	void setStreet(std::string str);
	void setCity(std::string city);
	void setCountry(std::string country);

	//Getters
	std::string getHouse();
	std::string getStreet();
	std::string getCity();
	std::string getCountry();

	//cin operator overloading
	friend std::istream& operator >>(std::istream& input, Address& add);

	/*Address(Address& add) {
		add.city = this->city;
		add.country = this->country;
		add.house = this->house;
		add.street = this->street;
	}*/
};
