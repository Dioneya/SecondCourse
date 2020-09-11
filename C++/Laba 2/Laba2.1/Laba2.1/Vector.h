#pragma once
class Vector
{
private:
    int* arr;
    int lenght;
public:
    Vector(int); //конструктор

    ~Vector(); // деструктор

    void printVector(); // вывод массива
    void ConvertMatrix(int**, int, int);

    int& operator[] (const int); // перегрузка []

    void operator++(); // версия префикс
    void operator--(); // версия префикс

    void operator++(int); // версия постфикс
    void operator--(int); // версия постфикс
};