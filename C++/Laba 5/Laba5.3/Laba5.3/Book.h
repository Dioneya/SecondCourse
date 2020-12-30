#pragma once
#include <string>
#include <iostream>
#include <iomanip>
class Book
{
private:
	
public:
	std::string name;
	std::string author;
	int year;
	Book(std::string _name, std::string _author, int _year);
	
	void Print() 
	{
		std::cout << std::setw(30) << std::left << name;
		std::cout << std::setw(20) << std::left << author;
		std::cout << std::setw(20) << std::left << year<<std::endl;
	}
};

