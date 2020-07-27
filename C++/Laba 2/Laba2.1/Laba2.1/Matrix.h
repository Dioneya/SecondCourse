#pragma once
class Matrix
{
private:
    int** arr;
    int row,
        column;
public:
    Matrix(int, int); // �����������

    ~Matrix(); // ����������

    int at(int, int); // ��������� �������� �� ������� � ������� 

    void setAt(int, int, int); // �������� �������� �� ������� � �������

    int getRowLenght(); // �������� ���. ����� � �������

    int getColumnLenght(); // �������� ���. �������� � �������

    void printMatrix();

    void operator++(); // ������ �������
    void operator--(); // ������ �������

    void operator++(int); // ������ ��������
    void operator--(int); // ������ ��������
};