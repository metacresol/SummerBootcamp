#include <stdio.h>
#include <string.h>
#include <conio.h>
void main()
{
    char s[256];
    int hash[256] = {0};
    printf("enter the string : ");
    gets(s);
    for (int i = 0; i < strlen(s); i++)
    {
        hash[s[i]]++;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if (hash[s[i]] == 1)
        {
            printf("first non repeating character is %c\n", s[i]);
            return;
        }
    }
    printf("there is no unique character");
}