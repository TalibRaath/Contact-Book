#include "Contact.h"

Contact::Contact() {
	this->address = new Address;
	this->email_address = "";
	this->first_name = "";
	this->last_name = "";
	this->mobile_number = "";
}

Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number,
	std::string email_address, Address* address) {

	this->first_name = first_name;
	this->last_name = last_name;
	this->mobile_number = mobile_number;
	this->email_address = email_address;
	isinputvalid(email_address, "email");
	isinputvalid(mobile_number, "mobile_number");

	this->address = address;
}

void Contact::setFirst_Name(std::string first_name) {
	this->first_name = first_name;
}

void Contact::setLast_Name(std::string last_name) {
	this->last_name = last_name;
}

void Contact::setMobile_Number(std::string mobile_number) {
	this->mobile_number = mobile_number;
}

void Contact::setEmail_address(std::string email_address) {
	this->email_address = email_address;
}

//Getters
std::string Contact::getFirst_Name() {
	return this->first_name;
}

std::string Contact::getLast_Name() {
	return this->last_name;
}

std::string Contact::getMobile_Number() {
	return this->mobile_number;
}

std::string Contact:: getEmail_Address() {
	return this->email_address;
}

bool Contact::equals(const Contact &contact)
{
	if (this->first_name == contact.first_name && this->last_name == contact.last_name
		&& this->mobile_number == contact.mobile_number 
		&& this->email_address == contact.email_address && contact.address->equals(*address))
		return true;

	return false;
}

Contact *Contact::copy_contact(){
	Contact *contact = new Contact;
	contact->address = this->address->copy_address();
	contact->first_name = this->first_name;
	contact->last_name = this->last_name;
	contact->email_address = this->email_address;
	contact->mobile_number = this->mobile_number;
	return contact;
}

//Address Printing Function
void Contact::AddressPrint() {
	address->print_address();
}

//copy constructor
Contact::Contact(Contact& contact) {
	this->first_name = contact.first_name;
	this->last_name = contact.last_name;
	this->mobile_number = contact.mobile_number;
	this->email_address = contact.email_address;
	this->address = contact.GetAddressObj()->copy_address();
}

//Functiom to check is input is valid
void Contact::isinputvalid(std::string input,std::string type) {

	if (type == "email") 
		if(input.find('@'))
		do {
			std::cout << "Enter Email Again: ";
			std::cin >> this->email_address;
		} while (email_address.find("@")==false);

	if (type == "mobile_number")
		if (input.size() != 11){
			do {
				std::cout << "Enter MObile Number Again: ";
				std::cin >> this->mobile_number;
			} while (mobile_number.size() != 11);
		}
}

//operator overloading for input

std::istream& operator >>(std::istream& input, Contact& contact) {

	std::cout << "Enter First Name: ";
	input >> contact.first_name;
	std::cout << "Enter Last Name: ";
	input >> contact.last_name;
	std::cout << "Enter Mobile Number: ";
	input >> contact.mobile_number;
	contact.isinputvalid(contact.mobile_number, "mobile_number");
	std::cout << "Enter Email Address: ";
	input >> contact.email_address;
	contact.isinputvalid(contact.mobile_number, "email");

	return input;
}

//Function to return the Address 
Address* Contact::GetAddressObj() {
	return address;
}

void Contact::setAddress(Address add) {
	address = new Address;
	*this->address = add;
}