//Вариант 7, задание №1, Кунов Никита
#include <ctime>
#include <clocale>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int processArray(float n[],int len, float arr[],float min_rnd, float max_rnd)
{
#pragma region Присовим значения массива от 20.0 до 100.0
    setlocale(LC_ALL, "ru"); 
    srand(time(0)); // для того, чтобы рандом был разным
    float interval = max_rnd - min_rnd;
    for (int i = 0; i < len; i++)  
    {
        n[i] = min_rnd + (rand() % (int)interval); // мин. граница рандом для сдвига отсчёта + рандомное число на интервале 
        printf("%g ",n[i]);
    }
#pragma endregion

#pragma region Нахождение минимального элемента массива
    float min_elem = 0;

    for (int i = 0; i < len; i++)
    {
        if (min_elem == 0 || min_elem > n[i])
        {
            min_elem = n[i];
        }
    }
    printf("\nmin Item = %d\n",(int)min_elem);
#pragma endregion


#pragma region получим новый массив где элемент это разница между n[i] и минимальным элементом из n[]
    for (int i = 0; i < len; i++)
    {
        arr[i] = n[i] - min_elem;
        printf("%g ",arr[i]);
    }
    printf("\n");
#pragma endregion
    
#pragma region Сформировать выходной вещественный массив, в котором все элементы, стоящие до позиции минимального элемента включительно, повторяют элементы входного массива, а остальные равны минимальному элементу массива
    bool elemEqualMin = false;
    for (int i = 0; i < len; i++)
    {
        if (n[i] == min_elem)
        {
            elemEqualMin = true;
        }
        if (elemEqualMin)
        {
            n[i] = min_elem;
        }
        printf("%g ",n[i]);
    }
#pragma endregion

    return min_elem;
}

int main()
{
    float n[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    float arr[15];

    processArray(n, sizeof(n) / sizeof(float),arr,20.0, 100.0);
}

