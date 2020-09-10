#include "Matrix.h"
#include "Vector.h"
using namespace std;

int main()
{
    Matrix matrix(5,5);
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

