#include <stdio.h>

int main()
{
    int r, c;
    printf("enter rows and columns of a matrix");
    scanf("%d %d", &r, &c);
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    // reverse the rows of the  matrix
    for (int i = 0; i < r; i++)
    {
        int start = 0;
        int end = c - 1;
        while (start < end)
        {
            int temp = arr[i][start];
            arr[i][start] = arr[i][end];
            arr[i][end] = temp;
            start++;
            end--;
        }
    }
    // reverse the columns of the matrix
    for (int i = 0; i < r; i++)
    {
        int st = 0;
        int end = r - 1;
        while (st < end)
        {
            int temp = arr[st][i];
            arr[st][i] = arr[end][i];
            arr[end][i] = temp;
            st++;
            end--;
        }
    }

    // printing the rotated matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}