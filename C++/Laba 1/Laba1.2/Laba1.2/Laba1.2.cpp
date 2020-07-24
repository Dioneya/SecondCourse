
#include <iostream>
using namespace std;


int SumOfFactorials(int i, int j)
{
	int first_num = 1;
	for (int k = 1; k <= i; k++) {
		first_num = first_num * k;
	}
	int second_num = 1;
	for (int k = 1; k <= j; k++) {
		second_num = second_num * k;
	}

	int res = first_num + second_num;
	
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
			cout << *(*(x + i) + j) << " ";
		}
		cout<<endl;
	}	
	cout << endl;
}

void ProcessArray(int **x, int n, int m)
{
	int cnt = n;
#pragma region Удалим ненужные строки из массива
	
	for (int i = 0; i < n; i += 2, cnt--)
	{
		delete[] * (x + i);
	}
#pragma endregion

	
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
}

