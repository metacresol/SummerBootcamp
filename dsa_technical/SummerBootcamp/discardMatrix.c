#include <stdio.h>
void main()
{
    int r, c;
    printf("enter the values for row and column");
    scanf("%d %d", &r, &c);
    int matrix[r][c];
    int max = 0;
    int idx;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += matrix[i][j];
        }
        if (sum > max)
        {
            max = sum;
            idx = i;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (idx != i)
                printf("%d", matrix[i][j]);
            else
                continue;
        }
        printf("\n");
    }
}