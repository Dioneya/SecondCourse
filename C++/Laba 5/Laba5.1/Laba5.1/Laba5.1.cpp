// Laba5.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "DataManager.h"
int main()
{
    DataManager<int> intManager;
    DataManager<char> charManager;

    for (int i = 0; i < 66 ; ++i) 
    {
        intManager.push(i);
    }
    intManager.pop();
    intManager.Print();
}
