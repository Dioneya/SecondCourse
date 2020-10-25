#include "Game.h"

Game::Player::Player() {}

Game::Player::Player(int _money) { set_money(_money); }

void Game::Player::Make_Bet(int _money) { money -= _money; }
