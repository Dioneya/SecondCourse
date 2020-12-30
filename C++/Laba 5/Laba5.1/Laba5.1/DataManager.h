#pragma once
#include <fstream>
#include <iostream>
#include <string>
template <typename T>
class DataManager
{
public: 
	void push(T elem) 
	{
		lastElemIndex++;

		if (lastElemIndex == LENGHT)
			WriteFile();

		array[lastElemIndex] = elem;
		InsertSort(array, lastElemIndex);
	}
	
	void push(T elems[], size_t n)
	{
		for (int i = 0; i < n; ++i)
			push(elems[i]);
	}
	
	T peek()
	{
		return lastElemIndex < 2 ? 0 : array[lastElemIndex - 1];
	}
	T pop()
	{
		if (lastElemIndex == -1) 
		{
			if (lastElemIndex != -1)
				ReadFile();
			
		}
		T elem = lastElemIndex != -1 ? array[lastElemIndex] : 0;
		lastElemIndex--;

		return elem;
	}
	char popLower() { return ' '; }

	char popUpper() { return ' '; }

	void Print()
	{
		if(lastElemIndex!=-1)
			std::copy(array, array + lastElemIndex, std::ostream_iterator<T>(std::cout, " "));
	}
private:
	static int const LENGHT = 64;
	int lastElemIndex = -1;
	T array[LENGHT];

	void InsertSort(T* mas, int n) 
	{
		for (int i = 0; i < n - 1; i++)
		{
			int key = i + 1;
			T temp = mas[key];
			for (int j = i + 1; j > 0; j--)
			{
				if (temp < mas[j - 1])
				{
					mas[j] = mas[j - 1];
					key = j - 1;
				}
			}
			mas[key] = temp;
		}
	} //сортировка вставками
	
	void WriteFile() 
	{
		std::string filepath("D:\\laba5.1");
		std::ofstream out(filepath + "Temp\\dump.dat", std::ios::app);
		if (out.is_open())
		{
			for (int i = 0; i < LENGHT; ++i)
				out << array[i] << std::endl;
		}
		out.close();
		lastElemIndex = 0;
	}
	
	void ReadFile()
	{
		T elem;
		std::string filepath("D:\\laba5.1");
		std::ifstream in(filepath + "Temp\\dump.dat"); // окрываем файл дл€ чтени€
		if (in.is_open())
		{
			int cnt = 0;
			lastElemIndex = 0;
			while (in>> elem || lastElemIndex != LENGHT)
			{
				push(elem);
			}
		}
		in.close();
	}
};

template<>
char DataManager<char>::popLower()
{
	char elem = lastElemIndex != -1 ? array[lastElemIndex] : 0;
	elem = tolower(elem);
	lastElemIndex--;

	return elem;
}

template<>
char DataManager<char>::popUpper()
{
	char elem = lastElemIndex != -1 ? array[lastElemIndex] : 0;
	elem = toupper(elem);
	lastElemIndex--;

	return elem;
}