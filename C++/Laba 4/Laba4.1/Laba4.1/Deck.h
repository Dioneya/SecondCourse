#include <iostream>
#include <time.h>
#include <vector>
#include "Card.h"
#include <random>
#include <algorithm>
#pragma once


class Deck
{

private:
	int lenght = 52;
	std::vector<Card> deck;
	void Shuffle(); //�-��� ����� ���������� �����

public:
	Deck();
	Card take_card();
	void print_Deck(); //�������� ����� ���� ���� �� ������
};

