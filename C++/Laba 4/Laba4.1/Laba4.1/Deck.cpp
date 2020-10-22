#include "Deck.h"


Deck::Deck() 
{ 
	std::string values[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	for (int i = 0; i < lenght/4; ++i) 
	{
		Card cards[4] = {  
			Card(values[i], Card::Suits::Hearts), 
			Card(values[i], Card::Suits::Clubs),
			Card(values[i], Card::Suits::Diamonds),
			Card(values[i], Card::Suits::Spades)
		};
		for (int j = 0; j < 4; ++j) deck.push_back(cards[j]);
	}

	Shuffle();
}

void Deck::Shuffle() 
{
	auto rng = std::default_random_engine{};
	std::random_device();
	std::shuffle(std::begin(deck), std::end(deck), rng);
}

void Deck::print_Deck()
{
	for (Card var : deck) 
	{

		std::cout << var.get_value();
		std::wcout << var.get_suit() << std::endl;
	}
}


Card Deck::take_card()
{
	Card card = deck.back();
	deck.pop_back();
	lenght-=1;
	return card;
}
