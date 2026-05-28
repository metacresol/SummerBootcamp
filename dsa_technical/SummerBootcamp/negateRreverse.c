#include <stdio.h>
int main()
{
    int r, c;
    printf("enter the values of rows and column\n");
    scanf("%d %d", &r, &c);
    int arr[r][c];
    // for entering the data.
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    // for negating the elements of even row
    for (int i = 0; i < r; i += 2)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = -arr[i][j];
        }
    }
    // for reversing the matrix
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c / 2; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][c - j - 1];
            arr[i][c - j - 1] = temp;
        }
    }
    // for printing the matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
        
    }
    return 0;
}