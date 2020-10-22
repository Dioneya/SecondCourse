#include "Card.h"
#include <vector>
#pragma once
class Player
{
public:

	Player();
	Player(int);

	void ReceiveCard(Card);
	void Add_Money(int);
	void set_money(int);
	void Make_Bet(int);
	std::vector<Card> get_cards();

	void ClearRound();

private:

	std::vector<Card> cards;
	int money = 0;
	int points = 0;

};

