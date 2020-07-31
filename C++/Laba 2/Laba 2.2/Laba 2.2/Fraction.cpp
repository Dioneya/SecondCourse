#include <iostream>
#include "Fraction.h"

Fraction::Fraction(int numer, int denomin)
{
    numerator = numer;
    denominator = denomin;

    count++;

    PrintFraction();
}
Fraction::~Fraction()
{
    //delete this;
}

void Fraction::PrintFraction()
{
    printf("%d/%d\n", numerator, denominator);
}

int Fraction::gcd(int a, int b)
{
    while (a > 0 && b > 0)

        if (a > b)
            a %= b;

        else
            b %= a;

    return a + b;
}

void Fraction::reduce()
{
    int NOD = gcd(numerator, denominator);
    numerator /= NOD;
    denominator /= NOD;
    PrintFraction();
}

void Fraction::PrintNumOfFraction() 
{
    printf("%d\n", Fraction::count);
}

Fraction Fraction::operator+(Fraction term) 
{
    int sum_numer = 0,
        sum_denomin = 0;
    if (term.denominator == denominator)
    {
        sum_denomin = denominator;
        sum_numer = term.numerator + numerator;
    }
    else
    {
        sum_denomin = denominator * term.denominator;
        sum_numer = (numerator * term.denominator) + (term.numerator * denominator);
    }
    Fraction sum(sum_numer, sum_denomin);
    return sum;
}

Fraction Fraction::operator-(Fraction substr)
{
    int dif_numer = 0,
        dif_denomin = 0;
    if (substr.denominator == denominator)
    {
        dif_denomin = denominator;
        dif_numer = numerator - substr.numerator;
    }
    else
    {
        dif_denomin = denominator * substr.denominator;
        dif_numer = (numerator * substr.denominator) - (substr.numerator * denominator);
    }

    Fraction dif(dif_numer, dif_denomin);
    return dif;
}

Fraction Fraction::operator*(Fraction mult)
{
    int product_numer = mult.numerator * numerator,
        product_denomin = mult.denominator * denominator;
    Fraction product(product_numer, product_denomin);
    return product;
}

Fraction Fraction::operator/(Fraction divisor)
{
    int quotient_numer = numerator * divisor.denominator,
        quotient_denomin = denominator * divisor.numerator;
    Fraction quotient(quotient_numer, quotient_denomin);
    return quotient;
}