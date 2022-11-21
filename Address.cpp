#include "Address.h"

Address::Address() {
	this->house = "";
	this->street = "";
	this->city = "";
	this->country = "";
}

Address::Address(std::string house, std::string street, std::string city, std::string country) {
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;

}

void Address::sethouse(std::string h) {
	this->house = h;
}

void Address::setStreet(std::string str) {
	this->street = str;
}

void Address:: setCity(std::string city) {
	this->city = city;
}

void Address:: setCountry(std::string country) {
	this->country = country;
}

std::string Address::getHouse() {
	return this->house;
}

std::string Address:: getStreet() {
	return this->street;
}

std::string Address::getCity() {
	return this->city;
}

std::string Address::getCountry() {
	return this->country;
}

bool Address::equals(const Address& address)
{
	if (this->city == address.city && this->house == address.house
		&& this->street == address.street && this->country == address.country)
		return true;

	return false;
}

void Address::print_address()
{
	std::cout << this->house  << ' ' << this->street << ' ' << 
		this->city << ' ' << this->country << std::endl;
}

Address* Address::copy_address()
{
	Address* add = new Address;
	add->city = this->city;
	add->country = this->country;
	add->house = this->house;
	add->street = this->street;

	return add;
}

//operator overloading to get input
std::istream& operator >>(std::istream& input, Address& add) {
	std::cout << "Enter House: ";
	input >> add.house;
	std::cout << "Enter Street: ";
	input >> add.street;
	std::cout << "Enter City: ";
	input >> add.city;
	std::cout << "Enter Country:";
	input >> add.country;
	return input;
}