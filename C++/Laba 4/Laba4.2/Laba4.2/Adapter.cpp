#include "Adapter.h"

std::string Adapter::format() 
{
	return "»м€ класса: " + (std::string)typeid(this).name() + " ”казатель на класс: " + (std::string)typeid(*this).name();
}

void Adapter::prettyPrint(const IFormattable& object)
{
	std::cout<< "»м€ класса: " <<typeid(object).name() << " —сылка на класс: " << typeid(&object).name()<< std::endl;
}