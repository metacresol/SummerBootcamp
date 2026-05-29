#include <stdio.h>
//incomplete
#include <string.h>
#include <conio.h>
int main()
{
    char s[101];
    char t[101];
    gets(s);
    gets(t);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
    printf("%s", &s);
    return 0;
}