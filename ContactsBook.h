#pragma once
#include "Address.h"
#include "Contact.h"
#include"Search_history.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB


class ContactsBook {
private:
	Contact *contacts_list; // array of contacts
	int size_of_contacts = 0;   // storage limit
    int contacts_count;     // total contacts currently stored, next contact will be 
						    // stored at this count plus 1
	history search_hist;
public:

	ContactsBook();
	void add_contact(Contact& contact);
    int total_contacts();
	void setsize(int size);

	Contact* search_contact(std::string search);

	ContactsBook(int size_of_list);

	void print_contacts_unsorted();
	void print_contacts_sorted(std::string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
							 // Duplicate means exact equal, this means if
	
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);

	void edit_contact(Contact& contact);
	ContactsBook(ContactsBook& book);

private:
    bool compare(Contact& contact1, Contact& contact2, std::string choice);
	bool full();
	void resize_list();
	void sort_contacts_list(Contact *contacts_list, std::string choice);
	Contact *GetContactCopy();
	void printmatchedcontact(Contact search_contact) const;
	void delete_contact(int index);
};
