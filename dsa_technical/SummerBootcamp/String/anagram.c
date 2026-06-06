#include <stdio.h>
#include <string.h>
void main()
{
    char s1[256];
    char s2[256];
    printf("enter first string: ");
    scanf("%s", s1);
    printf("enter second string: ");
    scanf("%s", s2);
    int hash[256] = {0};
    if (strlen(s1) != strlen(s2))
        printf(" given two strings are not anagram");
    for (int i = 0; i < strlen(s1); i++)
    {
        hash[s1[i]]++;
    }
    for (int i = 0; i < strlen(s2); i++)
    {
        hash[s2[i]]--;
    }
    int ans = 0;
    for (int i = 0; i < strlen(s1); i++)
    {
        if (hash[s1[i]] != 0)
        {
            printf(" given two strings are not anagram");
            return;
        }
    }
    printf("given two strings are  anagram");
}
