#pragma once
#include "Deck.h"
class Game
{
private:
	//Класс для общих особенностей и возможности у играющих
	class Playable 
	{
	public:
		Playable() {}

		int points = 0; //очки

		void set_money(int); //установка кол денег у играющего
		int get_money(); // получение кол денег у играющего
		std::vector<Card> get_cards(); // получить список карт у играющего на руке

		void ReceiveCard(Card); // Дать карту играющему 
		void Add_Money(int); // Добавить денег играющему
		void ClearRound(); // обнулить очки и карты у игрока 

	protected:
		std::vector<Card> cards; // Карты у играющего на руке
		int money = 0; // кол денег
	};

	//Класс игрока
	class Player : public Playable
	{
	public:
		Player();
		Player(int);
		void Make_Bet(int); // Сделать ставку
	};
	//Класс Дилера
	class Dealer : public Playable 
	{
	private:
		bool isLimit = false;

	public:
		Dealer();
		Dealer(int);
		bool CheckCardLimit(); // проверка на лимит для взятие карт до 17 очей
		void Sub_Money(int); // вычитать деньги
	};

	Player player = Player(10000);
	Dealer dealer;
	Deck* decks; // колоды
	int bet = 0; // текущая ставка
	bool isLimit = false;

	void RoundStart(); // начать игровой раунд

	void PrimaryDistribution(); // Первая раздача по две карты
	void ShowInfo(); // Показ общей инофрмации
	void MakeInput();
	bool isDoubleAce();
	bool isBlackJack();

	void PrintDecksLenght(); // Показ длины колод
	void PrintDealerCards(); // Показ карты Дилера
	void PrintPlayerCards(); // Показ карты Игрока
	void PrintResult();
	
public: 
	Game();
	~Game();
	void StartGame();

};

