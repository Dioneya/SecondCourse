#include "Game.h"

void Game::Playable::ReceiveCard(Card card)
{
	cards.push_back(card);
	if (card.get_value() == "A")
		points += points + 11 >= 21 ? 1 : 11;
	else if (card.get_value() == "J" || card.get_value() == "Q" || card.get_value() == "K")
		points += 10;
	else
		points += std::stoi(card.get_value());
}

void Game::Playable::Add_Money(int _money) { money += _money; }

std::vector<Card> Game::Playable::get_cards() { return cards; }

void Game::Playable::ClearRound()
{
	points = 0;
	cards.clear();
}
int Game::Playable::get_money() { return money; }

void Game::Playable::set_money(int _money) { money = _money; }
