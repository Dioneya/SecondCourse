#include <iostream>
#include <clocale>
#include <ctime>
#include <fstream>
#include "Court.h"
#include "Sports_Facilities.h"

int main()
{
	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

#pragma region Инициализация объектов
	Stadium* stadiums[3];

	stadiums[0] = new Court("Лукоморье", "Газ-мяс", 5, 300,100,"grow");
	stadiums[0]->set_month(Stadium::June);

	stadiums[1] = new Sports_Facilities("Спорт-заведение Клубнячок", "Кукурузка", 6, 100, 200, "grow");
	stadiums[2] = new Sports_Facilities("Спорт-заведение Кукабара", "Петушок - Кэнди шоп", 6, 50, 200, "grow");
#pragma endregion

#pragma region Имитации игр в стадионах
	stadiums[0]->ImitateGame(1);
#pragma endregion

	for (int i = 0; i < 3; ++i) {
		stadiums[i]->print_Stadium_info(); 
		cout << typeid(*stadiums[i]).name() << endl << endl; // RTTI
		for (int j = 0; j < 200; ++j) 
		{
			stadiums[i]->ticket();
		}
	}

	for (int i = 0; i < 3; ++i) { delete stadiums[i]; }
}
