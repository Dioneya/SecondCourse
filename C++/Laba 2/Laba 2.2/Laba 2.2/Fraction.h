#pragma once
#include <iostream>
class Fraction
{
   
private:
    
    int numerator,    // числитель
        denominator;  // знаменатель
public:
    static int count;

    Fraction(int numer, int denomin);

    ~Fraction();

    void PrintFraction(); // вывод дроби

    static int gcd(int a, int b); // нахождение наибольшего общего делителя

    void reduce(); // сокращение дроби

    void PrintNumOfFraction();

    Fraction operator+(Fraction); // перегрузка +

    Fraction operator-(Fraction); // перегрузка -

    Fraction operator*(Fraction mult); // перегрузка *

    Fraction operator/(Fraction divisor); // перегрузка /
};
