#include <stdio.h>
#include <string.h>
void main()
{
    char s1[256];
    char s2[256];
    printf("enter first string: ");
    scanf("%s", s1);
    printf("enter second string: ");
    scanf("%s", s1);
    char hash[256] = {0};
    for (int i = 0; i < strlen(s1); i++)
    {
        hash[s1[i]]++;
    }
    for (int i = 0; i < strlen(s2); i++)
    {
        hash[s2[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (hash[i] != 0)
            printf(" given two strings are not anagram");
        break;
    }
    printf("given two strings are  anagram");
}
