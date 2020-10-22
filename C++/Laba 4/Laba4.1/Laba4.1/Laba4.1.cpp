// Laba4.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "Deck.h"
#include <io.h>
#include <fcntl.h>
int main()
{

    setlocale(LC_ALL, "rus");
    setlocale(LC_ALL, ".866");

    std::cout << "Hello World!\n";
    Deck deck;
    Card card = deck.take_card();
    std::cout << card;
    //deck.print_Deck();
}


