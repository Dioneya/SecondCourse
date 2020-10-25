#include "Card.h"
Card::Card(std::string v, Suits s)
{
	wchar_t suits[4] = { L'\u2665', L'\u2666',L'\u2663',L'\u2660'};

	value = v;
	suit = suits[(int)s];
}

std::string Card::get_value()
{
	return value;
}


wchar_t Card::get_suit()
{
	return suit;
}

std::ostream& operator<< (std::ostream& out, const Card& card)
{
	out << card.value;
	std::wcout<< card.suit;
	return out;
}