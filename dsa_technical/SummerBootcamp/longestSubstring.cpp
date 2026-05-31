#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    printf("Enter string: ");
    scanf("%s", s);

    int last[256];

    for (int i = 0; i < 256; i++)
        last[i] = -1;

    int left = 0;
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++)
    {
        if (last[s[right]] >= left)
        {
            left = last[s[right]] + 1;
        }

        last[s[right]] = right;

        int currLen = right - left + 1;

        if (currLen > maxLen)
            maxLen = currLen;
    }

    printf("Length of longest substring = %d", maxLen);

    return 0;
}