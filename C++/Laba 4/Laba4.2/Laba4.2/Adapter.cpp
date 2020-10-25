#include "Adapter.h"

std::string Adapter::format() 
{
	return "��� ������: " + (std::string)typeid(this).name() + " ��������� �� �����: " + (std::string)typeid(*this).name();
}

void Adapter::prettyPrint(const IFormattable& object)
{
	std::cout<< "��� ������: " <<typeid(object).name() << " ������ �� �����: " << typeid(&object).name()<< std::endl;
}