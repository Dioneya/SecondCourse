#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Stadium
{
private:
#pragma region �������� ���������� ������� � �������
	string adress;
	string club;
	int numOfSectors;
	int capacity;
	int attendance = 0;
#pragma endregion

	list<int> historyOfAttendance; // ������ �������� ������� ��� �������� ������
	int mid_attendance; // ������� ������� ���������
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
};
