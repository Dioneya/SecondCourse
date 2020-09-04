
#include <iostream>
#include < iomanip >
using namespace std;


int Factorial(int i) 
{
	int num = 1;
	for (int k = 1; k <= i; k++) {
		num = num * k;
	}
	return num;
}

int SumOfFactorials(int i, int j)
{
	int res = Factorial(i) + Factorial(j);
	return res;
}


void InitializeArray(int **x,int n, int m) 
{
	for (int i = 0; i < n; i++)  
	{
		for (int j = 0; j < m; j++)
		{
			*(*(x+i)+j) = SumOfFactorials(i,j); // то же, что и x[i][j] = ...;
		}
	}
}

void PrintArray(int **x, int n, int m) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cout<<setw(8)<< *(*(x + i) + j);
		}
		cout<<endl;
	}	
	cout << endl;
}

void ProcessArray(int **x, int n, int m)
{
	int cnt = n;

	int *y = new int[cnt*m]; // выделим память одномерному массиву
	int index = 0;
	for (int i = 1; i < n; i+=2) 
	{
		for (int j = 0; j < m; j++, index++)
		{
			*(y+index) = *(*(x + i) + j);
			cout << *(y + index) << " ";
		}
		delete[] * (x + i); //подчищаем обработанную строку
	}
}

void DeleteArray(int **arr, int rows) 
{
	for (int i = 0; i < rows; i += 2)
	{
		delete[] * (arr + i);
	}
}

int main()
{
#pragma region динамическое создание двумерного массива
	int** x = new int* [5];
	int row = 5, column = 5;
	for (int i = 0; i < row; i++)
	{
		*(x + i) = new int[column];
	}
#pragma endregion

	
	InitializeArray(x, row, column);
	PrintArray(x, row, column);
	ProcessArray(x, row, column);
	DeleteArray(x, 5);
}

