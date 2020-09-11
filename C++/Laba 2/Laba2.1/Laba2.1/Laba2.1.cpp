#include "Matrix.h"
#include "Vector.h"
using namespace std;

int main()
{
    Matrix matrix(5,5);
    matrix.printMatrix();

    Vector vector( (matrix.getRowLenght()/2) * matrix.getColumnLenght() );
    vector.ConvertMatrix(matrix.getArr(), matrix.getRowLenght(), matrix.getColumnLenght());
    
    /*for (int i = 1, k = 0; i < matrix.getRowLenght(); i+=2)
    {
        for (int j = 0; j < matrix.getColumnLenght(); j++, k++)
        {
            vector[k] = matrix.at(i,j);
        }
    }*/

    vector.printVector();
    matrix++;
    matrix.printMatrix();
    ++matrix;
    matrix.printMatrix();
}

