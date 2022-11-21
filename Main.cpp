#include<iostream>
#include"Address.h"
#include"Contact.h"
#include"ContactsBook.h"

Address* address() {
	Address* add = new Address;
	std::cin >> *add;
	return add;
}

int main() {
	int choice = 0;
	std::string search;
	std::string fname ="fn", lname ="ln", email= "email", mobile = "mobile";
	Contact contact;
	ContactsBook book;
	Address *add = new Address[10];
	do
	{
		std::cout << "----------Contact Book-----------\n";
		std::cout << "1-Create Contact List(from given size)\n2-Add New Contact\n";
		std::cout << "3-Merge Duplicates\n4-Store to File\n5-Load from File\n6-Print Contacts Sorted\n";
		std::cout << "7-Print Contacts\n8-Search Contacts\n9-Display Count of Contacts\n";
		std::cout << "0-Exit\nEnter Your Choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			int size;
			std::cout << "Enter size of Contact Book: ";
			std::cin >> size;
			std::cout << "Contact Book Created\n";
			book.setsize(size);
			break;
		case 2:
			std::cin >> contact;
			std::cin >> *add;
			contact.setAddress(*add);
			book.add_contact(contact);
			break;
		case 3:
			book.merge_duplicates();
			break;
		case 4:
			book.save_to_file("Load_from_file.txt");
			break;
		case 5:
			 book.load_from_file("Load_from_file.txt");
			break;
		case 6:
			book.print_contacts_sorted("first name");
			break;
		case 7:
			book.print_contacts_unsorted();
			break;
		case 8:
			std::cout << "Search Contact: ";
			std::cin >> search;
			book.search_contact(search);
			break;
		case 9:
			std::cout<<"Total Contacts: "<<book.total_contacts() << std::endl;
			break;
		}

		system("pause");
		system("cls");
	} while (choice != 0);




	//scenerio-1
	/*ContactsBook Book(5);
	Contact *contact = new Contact[5];
	Address* add = new Address[5];
	Address add1("1", "H Block", "Lahore", "Pakistan");
	Address add2("2", "k Block", "Lahore", "Pakistan");
	Address add3("3", "F Block", "Lahore", "Pakistan");
	Address add4("4", "A Block", "Lahore", "Pakistan");
	Address add5("5", "Z Block", "Lahore", "Pakistan");

	Contact contact1("Ahmad", "Raath", "03014111624", "ahmad@gmail.com", &add1);
	Contact contact2("Talib", "Husain", "03014111624", "Talib@gmail.com", &add2);
	Contact contact3("Zohaan", "Khadim", "03014111624", "Zohaan@gmail.com", &add3);
	Contact contact4("Noor", "Ahmad", "03014111624", "noor@gmail.com", &add3);
	Contact contact5("Usaman", "Ali", "03014111624", "usman@gmail.com", &add3);

	Book.add_contact(contact2);
	Book.add_contact(contact1);
	Book.add_contact(contact3);
	Book.add_contact(contact4);
	Book.add_contact(contact5);

	/*cout << "ENter the Data\n";
	for (int i = 0; i < 2; i++) {
		cin >> contact[i];
		cin >> add[i];
		contact[i].setAddress(add[i]);
		Book.add_contact(contact[i]);
	}
	cout << "Unsorted Contacts\n";
	Book.print_contacts_unsorted();
	cout << "Sorted Contacts\n";
	Book.print_contacts_sorted("first name");
	

	//scenerio-2
	cout<<"Total Counts = "<<Book.total_contacts()<<endl;

	Address add6("6", "k Block", "Lahore", "Pakistan");
	Address add7("7", "X Block", "Lahore", "Pakistan");

	Contact contact6("ALi", "Raath", "03014111624", "Ali@gmail.com", &add6);
	Contact contact7("sana", "Husain", "03014111624", "sana@gmail.com", &add7);

	Book.add_contact(contact6);
	Book.add_contact(contact7);

	cout << "Total Contacts After adding 2 moer: " << Book.total_contacts() << endl;
	*/
	//Scenero-3

	//ContactsBook book(5);

	//Address add1("365", "F Block", "Lahore", "Pakistan");
	//Address add2("895", "H Block", "Lahore", "Pakistan");
	//Address add3("120/1", "J Block", "Lahore", "Pakistan");
	//Address add4("164", "K Block", "Lahore", "Pakistan");

	//Contact contact1("Talib", "Raath", "03217330477" ,"RAath.@gmail.com", &add1);
	//Contact contact2("Fida", "Raath", "03014111624", "tariqq@gmail.com", &add2);
	//Contact contact3("Muhammad", "Aslam", "03015468953", "aslam@gmail.com", &add3);
	//Contact contact4("Khadim", "Husain", "03004801494", "khadim.nu@gmail.com", &add4);
	//Contact contact5("Khadim", "Husain", "03004801494", "khadim.nu@gmail.com", &add4);

	

	//book.add_contact(contact1);
	//book.add_contact(contact2);
	//book.add_contact(contact3);
	//book.add_contact(contact4);
	//book.add_contact(contact5);
	//book.merge_duplicates();
	
	//Scenerio-4
	//book.load_from_file("Load_from_file.txt");
	//book.print_contacts_sorted("first name");
	//book.save_to_file("Load_from_file.txt");


}