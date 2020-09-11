#include <iostream>
#include <cassert>
#include "Vector.h"


using namespace std;

Vector::Vector(int len)
{
    lenght = len;
    arr = new int[len];
}

Vector::~Vector() 
{
    delete[] arr;
}

void Vector::printVector() 
{
    for (int i = 0; i < lenght; i++) 
    {
        cout << arr[i]<<" ";
    }
    cout << endl;
}

void Vector::ConvertMatrix(int** matrix, int row, int column) 
{
    for (int i = 1, k = 0; i < row; i += 2)
    {
        for (int j = 0; j < column; j++, k++)
        {
            arr[k] = matrix[i][j];
        }
    }
}

int& Vector::operator[] (const int index)
{
    assert(index >= 0 && index < lenght);

    return arr[index];
}

void Vector::operator++()
{
    for (int i = 0; i < lenght; i++) 
    {
        arr[i]++;
    }
}

void Vector::operator--()
{
    for (int i = 0; i < lenght; i++)
    {
        arr[i]--;
    }
}

void Vector::operator++(int)
{
    for (int i = 0; i < lenght; i++)
    {
        ++arr[i];
    }
}

void Vector::operator--(int)
{
    for (int i = 0; i < lenght; i++)
    {
        --arr[i];
    }
}