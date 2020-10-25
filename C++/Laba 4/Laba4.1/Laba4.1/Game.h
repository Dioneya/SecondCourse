#pragma once
#include "Deck.h"
class Game
{
private:
	//����� ��� ����� ������������ � ����������� � ��������
	class Playable 
	{
	public:
		Playable() {}

		int points = 0; //����

		void set_money(int); //��������� ��� ����� � ���������
		int get_money(); // ��������� ��� ����� � ���������
		std::vector<Card> get_cards(); // �������� ������ ���� � ��������� �� ����

		void ReceiveCard(Card); // ���� ����� ��������� 
		void Add_Money(int); // �������� ����� ���������
		void ClearRound(); // �������� ���� � ����� � ������ 

	protected:
		std::vector<Card> cards; // ����� � ��������� �� ����
		int money = 0; // ��� �����
	};

	//����� ������
	class Player : public Playable
	{
	public:
		Player();
		Player(int);
		void Make_Bet(int); // ������� ������
	};
	//����� ������
	class Dealer : public Playable 
	{
	private:
		bool isLimit = false;

	public:
		Dealer();
		Dealer(int);
		bool CheckCardLimit(); // �������� �� ����� ��� ������ ���� �� 17 ����
		void Sub_Money(int); // �������� ������
	};

	Player player = Player(10000);
	Dealer dealer;
	Deck* decks; // ������
	int bet = 0; // ������� ������
	bool isLimit = false;

	void RoundStart(); // ������ ������� �����

	void PrimaryDistribution(); // ������ ������� �� ��� �����
	void ShowInfo(); // ����� ����� ����������
	void MakeInput();
	bool isDoubleAce();
	bool isBlackJack();

	void PrintDecksLenght(); // ����� ����� �����
	void PrintDealerCards(); // ����� ����� ������
	void PrintPlayerCards(); // ����� ����� ������
	void PrintResult();
	
public: 
	Game();
	~Game();
	void StartGame();

};

