#include "Game.h"
Game::Game() { StartGame(); }
Game::~Game() { delete[] decks; }

void Game::StartGame() 
{
	srand(time(0));
	decks = new Deck[4]{ Deck(),Deck(),Deck() ,Deck() }; // ������� 4 �����
	bool continuePlay = true;
	int cntForShuffle = 0;
	while (continuePlay) 
	{
		RoundStart();
		bool isNormalChoise = false;
		
		while (!isNormalChoise) 
		{
			std::cout << "���������� ����? y/n" << std::endl;
			try
			{
				std::string choise;
				std::cin >> choise;
				
				if (choise == "n")
					continuePlay = false;
				else if (choise != "y" && choise != "n")
					throw "������ �����";
				isNormalChoise = true;
			}
			catch (const char* exception) 
			{
				std::cout << exception << std::endl;
			}
		}
		if (cntForShuffle == 4)
		{
			decks = new Deck[4]{ Deck(),Deck(),Deck() ,Deck() };
			cntForShuffle = 0;
			std::cout << "������ ����������";
		}

		cntForShuffle++;
	}
}


void Game::RoundStart()
{
	std::cout << "���� ������?" << std::endl;
	try 
	{
		bool isNormalBet = false;
		bet = 0;
		while (!isNormalBet) 
		{
			std::cin >> bet;
			if (bet > player.get_money() || bet <= 0)
				std::cout << "������������ ������" << std::endl;
			else
				isNormalBet = true;
		}
		player.Make_Bet(bet);
	}
	catch(...)
	{
		std::cout << "������ �����" << std::endl;
	}
	
	PrimaryDistribution();
	try 
	{
		if (isDoubleAce())
			throw "����������� � ��� ���� ����� !!!!";
		else if (isBlackJack())
			throw "����������� � ��� �������� !!!!";
		MakeInput();
	}

	catch (const char* exception) 
	{
		ShowInfo();
		std::cout << exception << " ��� �������:" << bet;
		player.Add_Money(bet + (1.5 * bet));
		std::cout << " �����: " << player.get_money() << std::endl;
	}
	
	player.ClearRound();
	dealer.ClearRound();
	
	
}

void Game::PrintResult() 
{
	if (player.points > dealer.points || dealer.points > 21)
	{
		std::cout << "�� ��������! ��� �������:" << bet;
		player.Add_Money(2 * bet);
		std::cout << " �����: " << player.get_money()<<std::endl;
	}
	else if (player.points == dealer.points)
	{
		std::cout << "������ ����!";
		player.Add_Money(bet);
		std::cout << " �����: " << player.get_money() << std::endl;
	}
	else
		std::cout << "�� ���������! �����:" << player.get_money() << std::endl;
}

bool Game::isDoubleAce() 
{
	return player.get_cards()[0].get_value() == "A" && player.get_cards()[1].get_value() == "A";
}

bool Game::isBlackJack() 
{
	bool firstCase = player.get_cards()[0].get_value() == "A" && (player.get_cards()[1].get_value() == "Q" || player.get_cards()[1].get_value() == "K" || player.get_cards()[1].get_value() == "J");
	bool secondCase = player.get_cards()[1].get_value() == "A" && (player.get_cards()[0].get_value() == "Q" || player.get_cards()[0].get_value() == "K" || player.get_cards()[0].get_value() == "J");
	return firstCase || secondCase;
}

void Game::MakeInput() 
{
	try
	{
		isLimit = false;
		bool isNormalChoise = false;
		int choise = 0;
		bool canDouble = true;
		while (!isNormalChoise)
		{

			ShowInfo();
			std::cout << "1. ������" << std::endl << "2. ���" << std::endl;
			if (canDouble && (player.points == 9 || player.points == 10 || player.points == 11))
				std::cout << "3. ������� ������" << std::endl;
			std::cin >> choise;
			if (choise == 1)
			{
				while (dealer.CheckCardLimit() || dealer.points < player.points)
					dealer.ReceiveCard(decks[(int)rand() % 4].take_card());
				break;
			}
			else if (choise == 2)
			{
				player.ReceiveCard(decks[(int)rand() % 4].take_card());
				if (player.points > 21)
				{
					throw "�������! �� ���������";
				}
			}
			else if (choise == 3)
			{
				player.Make_Bet(bet);
				bet += bet;
			}
			else
				std::cout << "������������ �����" << std::endl;

			canDouble = false;
		}
		ShowInfo();
		PrintResult();
	}
	catch (const char* exception)
	{
		std::cout << exception << std::endl;
	}
	catch (...)
	{
		std::cout << "������ �����" << std::endl;
	}
}

void Game::ShowInfo() 
{
	PrintDecksLenght();
	PrintDealerCards();
	PrintPlayerCards();
}

void Game::PrimaryDistribution() 
{
	dealer.ReceiveCard(decks[(int)rand() % 4].take_card());
	for (int i = 0; i < 2; ++i)
		player.ReceiveCard(decks[(int)rand() % 4].take_card());
}

void Game::PrintDealerCards() 
{
	std::vector<Card> dealerCards = dealer.get_cards();
	std::cout << "�����: ";
	for (Card card : dealerCards)
		std::cout << card;
	std::cout << std::endl;
	
}

void Game::PrintPlayerCards() 
{
	std::vector<Card> playerCards = player.get_cards();
	std::cout << "��: ";
	for (Card card : playerCards)
		std::cout << card;
	std::cout << std::endl;
}

void Game::PrintDecksLenght()
{
	std::cout << "������:";
	for (int i = 0; i < 4; ++i)
		std::cout << "[" << decks[i].lenght << "] ";
	std::cout << std::endl;
}



