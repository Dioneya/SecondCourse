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
    }
}

Matrix::~Matrix() 
{
    for (int i = 0; i < row; i++) 
    {

    }
    delete[] arr;
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