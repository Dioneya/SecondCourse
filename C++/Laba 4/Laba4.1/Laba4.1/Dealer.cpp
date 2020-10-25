#include "Game.h"
Game::Dealer::Dealer() {}


Game::Dealer::Dealer(int _money) { set_money(_money); }


bool Game::Dealer::CheckCardLimit()
{
	isLimit = points < 17;
	return isLimit;
}

void Game::Dealer::Sub_Money(int _money)
{
	money -= _money;
}