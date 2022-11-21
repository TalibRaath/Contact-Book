#include"Search_history.h"
#include<iostream>

history::history() {
	save_history.open("search history.txt", std::ios::app);
	read_history.open("search history.txt");

}

history::history(std::string searched) {

	save_history.open("search history.txt", std::ios::app);
}

void history::savehistory(std::string searched) {

	save_history << searched << "  ";
	save_history << tt->tm_hour << ":" << tt->tm_min << "  ";
	save_history << tt->tm_mday << '/' << tt->tm_mon << '/' << tt->tm_year + 1900 << std::endl;
}

void history::view_search_history() {
	
	std::string reading;
	while (!read_history.eof()){
		getline(read_history, reading);
		std::cout << reading << std::endl;
	}

}

history::~history() {
	save_history.close();
	read_history.close();
}
