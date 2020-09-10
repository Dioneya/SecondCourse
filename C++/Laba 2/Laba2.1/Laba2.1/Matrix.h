#pragma once
class Matrix
{
private:
    int** arr;
    int row,
        column;
public:
    Matrix(int, int); // конструктор

    ~Matrix(); // деструктор

    int at(int, int); // получение элемента по индексу в массиве 

    void setAt(int, int, int); // указание элемента по индексу в массиве

    int getRowLenght(); // получить кол. строк в массиве

    int getColumnLenght(); // получить кол. столбцов в массиве

    int factorial(int);

    int SumOfFactorials(int, int);

    void printMatrix();

    void operator++(); // версия префикс
    void operator--(); // версия префикс

    void operator++(int); // версия постфикс
    void operator--(int); // версия постфикс
};