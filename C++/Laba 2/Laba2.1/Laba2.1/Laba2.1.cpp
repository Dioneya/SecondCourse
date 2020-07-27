#include "Matrix.h"
#include "Vector.h"
using namespace std;

int factorial(int i)
{
    int res = 1;
    for (int k = 1; k <= i; k++) {
        res = res * k;
    }

    return res;
}

int SumOfFactorials(int i, int j)
{
    int first_num = factorial(i);
    
    int second_num = factorial(j);

    int res = first_num + second_num;

    return res;
}



int main()
{
    Matrix matrix(5,5);
    for (int i = 0; i < matrix.getRowLenght(); i++) 
    {
        for (int j = 0; j < matrix.getColumnLenght(); j++) 
        {
            matrix.setAt(i,j, SumOfFactorials(i,j) );
        }
    }
    matrix.printMatrix();

    Vector vector( (matrix.getRowLenght()/2) * matrix.getColumnLenght() );
    for (int i = 1, k = 0; i < matrix.getRowLenght(); i+=2)
    {
        for (int j = 0; j < matrix.getColumnLenght(); j++, k++)
        {
            vector[k] = matrix.at(i,j);
        }
    }

    vector.printVector();
}

