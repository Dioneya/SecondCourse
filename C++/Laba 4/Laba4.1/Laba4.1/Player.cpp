#include "Player.h"

Player::Player() {}

Player::Player(int _money) { set_money(_money); }

void Player::set_money(int _money) { money = _money; }

void Player::ReceiveCard(Card card) { cards.push_back(card); }

void Player::Add_Money(int _money) { money += _money; }

void Player::Make_Bet(int _money) { money -= _money; }

std::vector<Card> Player::get_cards() { return cards; }

void Player::ClearRound() 
{
	points = 0;
	cards.clear();
}

