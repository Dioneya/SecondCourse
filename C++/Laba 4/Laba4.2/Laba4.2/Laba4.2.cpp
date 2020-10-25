// Laba4.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Deck.h"
int main()
{
    setlocale(LC_ALL, "");
    Deck deck;
    //через наследование
    std::cout << "Вывод format()"<<std::endl<<deck.format() << std::endl;
    deck.prettyPrint(deck);

    //через объект
    std::cout << "Вывод format()" << std::endl << deck.adapter.format() << std::endl;
    deck.adapter.prettyPrint(deck);
}
