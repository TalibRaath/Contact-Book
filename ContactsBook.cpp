#include "ContactsBook.h"
#include<math.h>
#include <sstream>
#include<fstream>

ContactsBook::ContactsBook(){
	this->contacts_count = 0;
	this->size_of_contacts = 0;
	contacts_list = nullptr;
}

void ContactsBook::add_contact(Contact& contact)
{
	contacts_count++;

	if (full())
		resize_list();
		this->contacts_list[this->contacts_count-1] = contact;
}

 int ContactsBook::total_contacts()
{
	return this->contacts_count;
}

bool ContactsBook::full()
{
	if (contacts_count == size_of_contacts)
		return true;

	return false;
}

void ContactsBook::resize_list()
{
	this->size_of_contacts *= 2;
	Contact* resized = new Contact[this->size_of_contacts];

	for (int i = 0; i < this->contacts_count; i++) {
		resized[i] = *this->contacts_list[i].copy_contact();

	}
	delete[]contacts_list;
	contacts_list = NULL;
	contacts_list = resized;
}


Contact* ContactsBook::search_contact(std::string search)
{
	std::cout << "count : " << this->contacts_count << std::endl;
	std::cout << "Tottal : " << this->size_of_contacts << std::endl;

	search_hist.savehistory(search);
	int find[8];
	for (int i = 0; i < this->contacts_count; i++) {
		find[0] = contacts_list[i].getFirst_Name().find(search);
		find[1] = contacts_list[i].getLast_Name().find(search);
		find[2] = contacts_list[i].getEmail_Address().find(search);
		find[3] = contacts_list[i].getMobile_Number().find(search);
		find[4] = contacts_list[i].GetAddressObj()->getHouse().find(search);
		find[5] = contacts_list[i].GetAddressObj()->getCountry().find(search);
		find[6] = contacts_list[i].GetAddressObj()->getStreet().find(search);
		find[7] = contacts_list[i].GetAddressObj()->getHouse().find(search);
		if (find[0] > -1 || find[1] > -1 || find[2] > -1 || find[3] > -1 || find[4] > -1
			|| find[5] > -1 || find[6] > -1 || find[7] > -1)
		{
			std::cout << "Contact# " << i << std::endl;
			this->printmatchedcontact(contacts_list[i]);
		}
	}
	int select,choice;
	std::cout << "select Contact to view details: ";
	std::cin >> select;
	system("cls");
	std::cout << "Contact Details\n";
	this->printmatchedcontact(contacts_list[select]);
	std::cout << "1-Edit\n2-Delete\nSelect option: ";
	std::cin >> choice;

	if (choice == 1)
		this->edit_contact(contacts_list[select]);
	else if (choice == 2)
		delete_contact(select);
	return &contacts_list[select];
}


void ContactsBook::printmatchedcontact(Contact search_contact) const {
	std::cout << search_contact.getFirst_Name() << ',' << search_contact.getLast_Name()
		<< ',' << search_contact.getMobile_Number() << ",";

	std::cout << search_contact.getEmail_Address() << "\n";;
	search_contact.AddressPrint();
}


void ContactsBook::delete_contact(int index) {
	contacts_count--;
	for (int i = index; i < this->contacts_count; i++) {
		contacts_list[i - 1] = contacts_list[i];
	}
	std::cout << "Contact has been deleted succesfully\n";
}


ContactsBook::ContactsBook(int size_of_list)
{
	this->contacts_list = new Contact[size_of_list];
	this->contacts_count = 0;
	this->size_of_contacts = size_of_list;
}

Contact *ContactsBook::GetContactCopy() {
		return this->contacts_list->copy_contact();

}

void ContactsBook::print_contacts_sorted(std::string choice){

	Contact* copiedContact = new Contact[contacts_count];
	for (int i = 0; i < this->contacts_count; i++) {
		copiedContact[i] = contacts_list[i];
	}

	sort_contacts_list(copiedContact, choice);

	for (int i = 0; i < this->contacts_count; i++) {
		std::cout << copiedContact[i].getFirst_Name() << ',' << copiedContact[i].getLast_Name() 
			<< ',' << copiedContact[i].getMobile_Number() << ",";

		std::cout << copiedContact[i].getEmail_Address() << "\n";;
		copiedContact[i].AddressPrint();
	}

}

void ContactsBook::sort_contacts_list(Contact* contacts, std::string choice)
{
	Contact *temp = new Contact;

	for (int i = 0; i < this->contacts_count; i++) {
		for (int j = i+1; j < this->contacts_count; j++) {
			
			if (this->compare(contacts[i], contacts[j], choice)) {

				temp = contacts[i].copy_contact();
				contacts[i] = *contacts[j].copy_contact();
				contacts[j] = *temp;
				delete temp;
				temp = NULL;
			}
		}
	}
}

void ContactsBook::merge_duplicates()
{
	Contact *temp = new Contact;
	int count = this->contacts_count;
	for (int i = 0; i < this->contacts_count; i++) {
		for (int j = i+1; j < this->contacts_count; j++) {

			if (this->contacts_list[i].equals(contacts_list[j])) {

				for (int k = j; k < this->contacts_count-1; k++) {
					*temp = contacts_list[k];
					contacts_list[k] = contacts_list[k + 1];
					contacts_list[k + 1] = *temp;
				}
				contacts_count--;
			}
		}
	}

	//Printing the merged contacts only
	std::cout << "Total Merged Contacst: " << count- contacts_count <<std:: endl;
	for (int i = contacts_count; i < count; i++) {
		std::cout << contacts_list[i].getFirst_Name() << ',' << contacts_list[i].getLast_Name() 
			<< ',' << contacts_list[i].getMobile_Number() << ",";

		std::cout << contacts_list[i].getEmail_Address() << "\n";
		contacts_list[i].AddressPrint();
	}

	delete temp;
	
}

void ContactsBook::load_from_file(std::string file_name) {

	std::ifstream load;
	int count;
	std::string fname, lname, mobile, email;
	std::string house, street, city, country, line;

	load.open(file_name);

	if (!load)
		std::cout << "This file can't be found\n";
	else {
		load >> this->size_of_contacts;
		load >> this->contacts_count;
		count = this->contacts_count;

		//count++;
		int i = 0;
		this->contacts_list = new Contact[size_of_contacts];
		Address add;
		std::string str;
		while (i < this->contacts_count)
		{
			if(i==0)
			std::getline(load, line);

			std::getline(load, line);
			std::stringstream ss(line);
			std::getline(ss, fname, ',');
			std::getline(ss, lname, ',');
			std::getline(ss, mobile, ',');
			std::getline(ss, email, ',');

			//setting the Contacts attributes load from file
			this->contacts_list[i].setFirst_Name(fname);
			this->contacts_list[i].setLast_Name(lname);
			this->contacts_list[i].setMobile_Number(mobile);
			this->contacts_list[i].setEmail_address(email);

			std::getline(load, line);
			std::stringstream address(line);
			std::getline(address, house, ',');
			std::getline(address, street, ',');
			std::getline(address, city, ',');
			std::getline(address, country, ',');

			//setting the address attributes load from file
			add.sethouse(house);
			add.setStreet(street);
			add.setCity(city);
			add.setCountry(country);
			this->contacts_list[i].setAddress(add);
			i++;
		}
	
		load.close();
	}
}

void ContactsBook::save_to_file(std::string file_name) 
{
	std::ofstream save;
	save.open(file_name);
	save << this->size_of_contacts << std::endl;
	save << contacts_count<<std::endl;
	Address* add;

	for (int i = 0; i < this->contacts_count; i++) {
		save << contacts_list[i].getFirst_Name() << "," << contacts_list[i].getLast_Name()
			<< "," << contacts_list[i].getMobile_Number() << ",";

		save << contacts_list[i].getEmail_Address() << std::endl;

		//Getting address attributes
		add = contacts_list[i].GetAddressObj();
		save<< add->getHouse()<<"," << add->getStreet()<<" "<<add->getCity()
			<<" "<<add->getCountry()<<std::endl;
	}
	std::cout << "Contacts Have Stored Successfully\n";
}

//Compare function
bool ContactsBook::compare(Contact& contact1, Contact& contact2, std::string choice) {

	if (choice == "first name") 
		return contact1.getFirst_Name() > contact2.getFirst_Name();

	else if(choice =="last name")
	return  contact1.getFirst_Name() > contact2.getFirst_Name();
	
}

//
void  ContactsBook::edit_contact(Contact& contact) {
	std::cin >> contact;
	Address* add = contact.GetAddressObj();
	std::cin >> *add;
}



//printing unsorted
void ContactsBook::print_contacts_unsorted() {

	for (int i = 0; i < this->contacts_count; i++) {
		std::cout << this->contacts_list[i].getFirst_Name() << ',' << 
		this->contacts_list[i].getLast_Name() << ',' << this->contacts_list[i].getMobile_Number() << ",";
		std::cout << this->contacts_list[i].getEmail_Address()<<'\n';
		this->contacts_list[i].AddressPrint();
	}
}


void ContactsBook:: setsize(int size) {
	this->contacts_list = new Contact[size];
	this->size_of_contacts = size;
	this->contacts_count = 0;
}

ContactsBook::ContactsBook(ContactsBook& book) {
	this->contacts_count = book.contacts_count;
	this->size_of_contacts = book.size_of_contacts;
	this->contacts_list = new Contact[size_of_contacts];
	
}
