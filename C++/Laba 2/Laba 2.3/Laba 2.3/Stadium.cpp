#include "Stadium.h"
#include <fstream>
#pragma region Конструкторы/деструкторы
Stadium::Stadium() 
{
	set_Stadium(" ", " ", 0, 0);
}

Stadium::Stadium(string adr_stad, string club_stad, int sectors, int stad_capacity)
{
	set_Stadium(adr_stad, club_stad, sectors, stad_capacity);
}

Stadium::~Stadium()
{
}
#pragma endregion

void Stadium::ImitateGame(int times)
{
	int capacity = get_capacity();
	for (int i = 0; i < times; i++)
	{
		set_attendance((rand() % capacity));
	}
}

#pragma region Сэттеры
void Stadium::set_Stadium(string adr_stad, string club_stad, int sectors, int stad_capacity)
{
	adress = adr_stad;
	club = club_stad;
	numOfSectors = sectors;
	capacity = stad_capacity;
}


void Stadium::set_attendance(int stad_attend)
{
	attendance = stad_attend;
	historyOfAttendance.push_back(calculate_fill_precent());
	mid_attendance = calculate_mid_attendance_precent();
}
#pragma endregion

#pragma region Гэттеры
string Stadium::get_adress() { return adress; }

string Stadium::get_club() { return club; }

int Stadium::get_num_of_sectors() { return numOfSectors; }

int Stadium::get_capacity() { return capacity; }

int Stadium::get_attendance() { return attendance; }

int Stadium::get_mid_attendance() { return mid_attendance; }

#pragma endregion

#pragma region Просчёты 
int Stadium::calculate_fill_precent()
{
	int fill_precent = (attendance * 100) / capacity;
	return fill_precent;
}

int Stadium::calculate_mid_attendance_precent()
{
	int res = 0;
	for (int i : historyOfAttendance)
	{
		res += i;
	}
	res /= historyOfAttendance.size();
	return res;
}
#pragma endregion

#pragma region Запись/чтения файл класса
void Stadium::serialize()
{
	string path = "lab.dat";
	ofstream fout;
	fout.open(path, ofstream::trunc);

	if (fout.is_open())
	{
		fout.write((char*)this, sizeof(Stadium));
	}

	fout.close();
}

void Stadium::serialize(const string& filename)
{
	ofstream fout;
	fout.open(filename, ofstream::trunc);

	if (fout.is_open())
	{
		fout.write((char*)this, sizeof(Stadium));
	}

	fout.close();
}

void Stadium::deserialize()
{
	string path = "lab.dat";
	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		fin.read((char*)this, sizeof(Stadium));
	}
	fin.close();
}

void Stadium::deserialize(const string& filename)
{
	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		fin.read((char*)this, sizeof(Stadium));
	}
	fin.close();
}
#pragma endregion



void Stadium::print_Stadium_info()
{
	cout << "Адрес: " << adress << "\nФутбольный клуб: " << club << "\nКоличество секторов: " << numOfSectors << "\nВместимость: " << capacity<< "\nСредний процент посещения: "<<mid_attendance<<"%\n"<<endl;
}
