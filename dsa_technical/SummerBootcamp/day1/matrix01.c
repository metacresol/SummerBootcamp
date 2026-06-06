// find sum of boundary elements of a matrix
#include <stdio.h>
void main()
{
    int r, c;
    printf("enter rows and columns of a matrix");
    scanf("%d%d", &r, &c);
    int arr[r][c];
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((i == 0) || (i == r - 1) || (j == 0) || (j == c - 1))
            {
                sum += arr[i][j];
            }
        }
    }
    printf("%d", sum);
}
