#include <iostream>
#include "Fraction.h"
using namespace std;

int Fraction::count = 0;

int main()
{
    Fraction first(2, 5);

    Fraction second(3,6);

    Fraction sum = first+second;
    Fraction mult = first * second;
    Fraction dev = first / second;
    Fraction dif = first - second;
    sum.reduce();

    printf("%d", Fraction::count);
}