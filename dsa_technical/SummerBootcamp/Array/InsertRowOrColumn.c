#include <stdio.h>

int main()
{
    int r, c;
    printf("enter rows and columns of a matrix");
    scanf("%d %d", &r, &c);
    int arr[100][100];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int choice, pos;
    printf("enter the choice and position :");
    scanf("%d %d", &choice, &pos);
    if (choice == 0)
    {

        for (int i = r; i > pos; i--)
        {
            for (int j = 0; j < c; j++)
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
        for (int i = 0; i < c; i++)
        {
            scanf("%d", &arr[pos][i]);
        }
        r++;
    }
    else
    {
        // c = c + 1;
        for (int i = 0; i < r; i++)
        {
            for (int j = c; j > pos; j--)
            {
                arr[i][j] = arr[i][j - 1];
            }
        }
        for (int i = 0; i < c; i++)
        {
            scanf("%d", &arr[i][pos]);
        }
        c++;
    }
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