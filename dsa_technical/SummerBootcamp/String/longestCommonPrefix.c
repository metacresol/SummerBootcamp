#include <stdio.h>
#include <string.h>

int main()
{
    char str[][100] = {"flower", "flow", "flight"};
    int n = 3;

    char prefix[100];
    strcpy(prefix, str[0]);

    for (int i = 1; i < n; i++)
    {
        int j = 0;

        while (prefix[j] && str[i][j] &&
               prefix[j] == str[i][j])
        {
            j++;
        }

        prefix[j] = '\0';

        if (strlen(prefix) == 0)
            break;
    }

    printf("Longest Common Prefix: %s", prefix);

    return 0;
}