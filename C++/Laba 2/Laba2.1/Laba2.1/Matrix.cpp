#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int row_arr, int column_arr)
{
    row = row_arr;
    column = column_arr;
    arr = new int* [row];
    for (int i = 0; i < row_arr; i++)
    {
        arr[i] = new int[column];
        for (int j = 0; j < column_arr; j++)
        {
            setAt(i, j, SumOfFactorials(i, j));
        }
    }
}

int Matrix::factorial(int i)
{
    int res = 1;
    for (int k = 1; k <= i; k++) {
        res = res * k;
    }

    return res;
}

int Matrix::SumOfFactorials(int i, int j)
{
    int first_num = factorial(i);

    int second_num = factorial(j);

    int res = first_num + second_num;

    return res;
}

Matrix::~Matrix() 
{
    for (int i = 0; i < row; i++) 
    {
        delete[] * (arr + i);
    }
}

int Matrix::at(int i, int j) 
{
    return arr[i][j];
}

void Matrix::setAt(int i, int j, int val) 
{
    arr[i][j] = val;
}

int Matrix::getColumnLenght() 
{
    return column;
}

int Matrix::getRowLenght() 
{
    return row;
}

int** Matrix::getArr() 
{
    return arr;
}

void Matrix::printMatrix() 
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << at(i,j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::operator++()
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            arr[i][j]++;
}

void Matrix::operator--()
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            arr[i][j]--;
}

void Matrix::operator++(int)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            ++arr[i][j];
}

void Matrix::operator--(int)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            --arr[i][j];
}