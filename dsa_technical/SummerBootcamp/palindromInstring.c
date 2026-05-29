#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    int start = 0;
    int end = strlen(s) - 1;

    while (start < end)
    {
        if (s[start] != s[end])
        {
            printf("String is not palindrome");
            return 0;
        }

        start++;
        end--;
    }

    printf("String is palindrome");

    return 0;
}
