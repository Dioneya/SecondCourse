#include <iostream>
#include <clocale>
#include <ctime>
#include <fstream>
#include "Stadium.h"

void Sort(Stadium* stadiums, Stadium stad) // параметр Stadium* - отвечает за стадионы созданные кучей, Stadium - стэком
{
	Stadium stadium_array[3] = {stadiums[0], stadiums[1], stad };

#pragma region Сортировка вставкой
	int key = 0;
	int i = 0;
	for (int j = 1; j < 3; j++) {
		Stadium key = stadium_array[j];
		i = j - 1;
		while (i >= 0 && stadium_array[i].get_mid_attendance() < key.get_mid_attendance()) {
			stadium_array[i + 1] = stadium_array[i];
			i = i - 1;
			stadium_array[i + 1] = key;
		}
	}
#pragma endregion

	for(Stadium i : stadium_array)
	{
		i.print_Stadium_info();
	}
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
	srand(time(NULL)); // рандомный рандом xDD

#pragma region Инициализация объектов
	Stadium* stadiums = new Stadium[2]; // кучей 
	stadiums[0].set_Stadium("Лукоморье", "Газ-мяс", 5, 300); //через set-метод
	stadiums[1].set_Stadium("Стадион-Мурашка", "Движ-мышь", 6, 350);
	Stadium stad3("Donbass", "Колбас-тим", 3, 240); // стэком через конструктор класса;
#pragma endregion

#pragma region Имитации игр в стадионах
	stadiums[0].ImitateGame(4);
	stadiums[1].ImitateGame(4);
	stad3.ImitateGame(4);
#pragma endregion

	Sort(stadiums, stad3);

	stad3.serialize("glic.txt"); // пример записи класса в файл

	Stadium* stad4 = new Stadium; //стадион для примера чтения класса с файла
	stad4->deserialize("glic.txt");
	stad4->print_Stadium_info();

}
