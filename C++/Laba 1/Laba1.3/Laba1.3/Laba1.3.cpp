#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

char* Strchr(char* s, int c, int arr_len)
{
    int len_sub = 0;
    bool isFound = false;
    for (int i = 0; i < arr_len; i++)
    {
        if (s[i] == c)
        {
            len_sub = arr_len - i;
            isFound = true;
            break;
        }
    }

    char* sub = new char[len_sub];
    if(isFound)
    {
        for (int i = 0; i < len_sub; i++)
        {
            sub[i] = s[arr_len - len_sub + i];
        }
        return sub;
    }
    else 
    {
        char null[] = "null";
        return null;
    }
}

int main()
{
    char text[] = "Some Text";
    printf("Find sub-string in: %s\n", text);
    char symbol;  
    scanf("%c", &symbol);
    char* find = strchr(text, symbol);
    printf("%s\n",find);
    int len = sizeof(text) / sizeof(text[0]);
    char* sub_str = Strchr(text, symbol, len);
    printf("%s\n", sub_str);
}
