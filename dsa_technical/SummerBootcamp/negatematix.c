// negate the elements of the matrix whose rows are even and interchange them
#include <stdio.h>
void main()
{
    int n;
    printf("enter the size of the square matrix");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = -arr[i][j];
            }
        }
    }
    // reverse the columns of the matrix
    for (int i = 0; i < n; i++)
    {
        int st = 0;
        int end = n - 1;
        while (st < end)
        {
            int temp = arr[st][i];
            arr[st][i] = arr[end][i];
            arr[end][i] = temp;
            st++;
            end--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}