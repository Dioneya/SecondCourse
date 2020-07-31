#pragma once
#include <iostream>
class Fraction
{
   
private:
    
    int numerator,    // ���������
        denominator;  // �����������
public:
    static int count;

    Fraction(int numer, int denomin);

    ~Fraction();

    void PrintFraction(); // ����� �����

    static int gcd(int a, int b); // ���������� ����������� ������ ��������

    void reduce(); // ���������� �����

    void PrintNumOfFraction();

    Fraction operator+(Fraction); // ���������� +

    Fraction operator-(Fraction); // ���������� -

    Fraction operator*(Fraction mult); // ���������� *

    Fraction operator/(Fraction divisor); // ���������� /
};
