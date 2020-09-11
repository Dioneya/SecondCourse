#pragma once
class Vector
{
private:
    int* arr;
    int lenght;
public:
    Vector(int); //�����������

    ~Vector(); // ����������

    void printVector(); // ����� �������
    void ConvertMatrix(int**, int, int);

    int& operator[] (const int); // ���������� []

    void operator++(); // ������ �������
    void operator--(); // ������ �������

    void operator++(int); // ������ ��������
    void operator--(int); // ������ ��������
};