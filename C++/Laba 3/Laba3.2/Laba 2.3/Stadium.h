#pragma once
#include <iostream>
#include <list>
#include <string>
#include "ISeasonTicketProvider.h"
using namespace std;

class Stadium: public ISeasonTicketProvider
{
private:
#pragma region Основные переменные заданые в условии
	string adress; // адрес
	string club; // клуб
	int numOfSectors; // число секторов
	int capacity; //вместимость
	int attendance = 0; // посещение
#pragma endregion

	list<int> historyOfAttendance; // Список хранящий историю кол зрителей матчей
	int mid_attendance; // средний процент посещения
protected:
	int numOfSubscription = 0; // кол абонентов
	int space; // площадь
	string typeOfCoverage; // тип покрытия
public:
	Stadium();
	Stadium(string, string, int, int); //перегруженный конструктор
	~Stadium();
	void set_Stadium(string, string, int, int); // установить параметры стадиона вручную
	void set_attendance(int); // установить число посетителей
	
	int calculate_mid_attendance_precent(); // просчёт среднего процента посещения 
	int calculate_fill_precent(); // просчёт процента заполнения стадиона за матч 

#pragma region Гэттеры
	string get_adress(); // получить адресс стадиона
	string get_club(); // получить футбольный клуб
	int get_num_of_sectors(); // полуичить кол. секторов 
	int get_capacity(); // получить вместимость стадиона
	int get_attendance(); // получить кол. посетителей
	int get_mid_attendance(); // получить средний процент посещения
#pragma endregion

#pragma region Запись/чтение файла класса
	void serialize(); //запись класса в файл
	void serialize(const string&); //запись класса в файл по указанному имени

	void deserialize(); //чтение файла класса 
	void deserialize(const string&); //чтение файла класса по указанному имени
#pragma endregion

	void ImitateGame(int); //имитация игр
	void print_Stadium_info(); //вывод информации о стадионе в консоль

	enum Month { January, February, March, April, May, June, July, August, September, October, November, December};
	void set_month(Month _month);
protected:
	Month month = January;
};
