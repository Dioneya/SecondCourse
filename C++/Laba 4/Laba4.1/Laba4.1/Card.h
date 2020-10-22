#pragma once
#include <string>
#include <iostream>
class Card
{
public:
	enum class Suits { Hearts, Diamonds, Spades, Clubs };
	Card(std::string, Suits s);

	std::string get_value();
	wchar_t get_suit();

	friend std::ostream& operator<< (std::ostream& out, const Card& card);
private:

	std::string value;
	wchar_t suit;
};
