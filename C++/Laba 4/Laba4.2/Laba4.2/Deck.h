#include <iostream>
#include <time.h>
#include <vector>
#include "Card.h"
#include <random>
#include <algorithm>
#include "Adapter.h"
#pragma once


class Deck: public Adapter
{

private:
	
	std::vector<Card> deck;
	void Shuffle(); //�-��� ����� ���������� �����

public:
	Deck();
	Adapter adapter;
	int lenght = 52;
	Card take_card();
	void print_Deck(); //�������� ����� ���� ���� �� ������
};

