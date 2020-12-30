// Laba5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
std::vector<Book> books;

struct sortClassByFirstKey
{
    bool operator() (const Book& i, const Book& j)
    {
        return (i.author < j.author);
    }
} sortByFirstKey;

struct sortClassBySecondtKey
{
    bool operator() (const Book& i, const Book& j)
    {
        return (i.name < j.name);
    }
} sortBySecondKey;

struct findClassByYear
{
    int _i, _j;
    findClassByYear(int i, int j) : _i(i), _j(j) {}
    void operator() (std::vector<Book> vec)
    {
        for (int i = 0; i < 3; ++i)
            if (vec[i].year >= _i && vec[i].year <= _j)
                vec[i].Print();
    }
} findByYear(1998, 2002);

int main()
{
    setlocale(0, "rus");
    Book firstBook("Lev", "Lol", 1995);
    Book secondBook("Aster", "King in the world", 2002);
    Book thirdBook("Buldog", "Pushkin", 1999);

    std::vector<Book> books ({ firstBook, secondBook, thirdBook });
    std::cout << std::endl << "Сортировка по первому ключу" << std::endl << std::endl;
    std::sort(books.begin(), books.end(), sortByFirstKey);
    for(int i = 0; i < 3; ++i)
    {
        books[i].Print();
    }
    std::cout << std::endl << "Сортировка по второму ключу" << std::endl << std::endl;
    std::sort(books.begin(), books.end(), sortBySecondKey);
    for (int i = 0; i < 3; ++i)
    {
        books[i].Print();
    }
    std::cout << std::endl << "Поиск по промежутку года" << std::endl << std::endl;
    findByYear(books);
}
