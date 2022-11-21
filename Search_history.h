#pragma once
#include<iostream>
#include"Contact.h"
#include<fstream>
#ifndef Search_history_h
#define Search_history_h


class history {
	time_t ctime = time(0);
	tm* tt = localtime(&ctime);
	std::ofstream save_history;
	std::ifstream read_history;

public:
	history();
	history(std::string searched);
	void savehistory(std::string searched);
	void view_search_history();
	~history();
};

#endif // !Search_history_h
