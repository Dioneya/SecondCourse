#pragma once
#include <iostream>
#include <list>
#include <string>
#include "ISeasonTicketProvider.h"
using namespace std;

class Stadium: public ISeasonTicketProvider
{
private:
#pragma region �������� ���������� ������� � �������
	string adress; // �����
	string club; // ����
	int numOfSectors; // ����� ��������
	int capacity; //�����������
	int attendance = 0; // ���������
#pragma endregion

	list<int> historyOfAttendance; // ������ �������� ������� ��� �������� ������
	int mid_attendance; // ������� ������� ���������
protected:
	int numOfSubscription = 0; // ��� ���������
	int space; // �������
	string typeOfCoverage; // ��� ��������
public:
	Stadium();
	Stadium(string, string, int, int); //������������� �����������
	~Stadium();
	void set_Stadium(string, string, int, int); // ���������� ��������� �������� �������
	void set_attendance(int); // ���������� ����� �����������
	
	int calculate_mid_attendance_precent(); // ������� �������� �������� ��������� 
	int calculate_fill_precent(); // ������� �������� ���������� �������� �� ���� 

#pragma region �������
	string get_adress(); // �������� ������ ��������
	string get_club(); // �������� ���������� ����
	int get_num_of_sectors(); // ��������� ���. �������� 
	int get_capacity(); // �������� ����������� ��������
	int get_attendance(); // �������� ���. �����������
	int get_mid_attendance(); // �������� ������� ������� ���������
#pragma endregion

#pragma region ������/������ ����� ������
	void serialize(); //������ ������ � ����
	void serialize(const string&); //������ ������ � ���� �� ���������� �����

	void deserialize(); //������ ����� ������ 
	void deserialize(const string&); //������ ����� ������ �� ���������� �����
#pragma endregion

	void ImitateGame(int); //�������� ���
	void print_Stadium_info(); //����� ���������� � �������� � �������

	enum Month { January, February, March, April, May, June, July, August, September, October, November, December};
	void set_month(Month _month);
protected:
	Month month = January;
};
