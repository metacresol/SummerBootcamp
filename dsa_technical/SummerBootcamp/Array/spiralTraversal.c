#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int top = 0, left = 0;
    int right = n - 1, bottom = n - 1;
    while (top <= bottom && left <= right)
    {
        // top row
        for (int i = left; i <= right; i++)
        {
            printf("%d ", arr[top][i]);
        }
        top++;
        // right column
        for (int i = top; i <= bottom; i++)
        {
            printf("%d ", arr[i][right]);
        }
        right--;
        // bottom row
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                printf("%d ", arr[bottom][i]);
            }
            bottom--;
            // left column
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", arr[bottom][left]);
            }
            left++;
        }
    }

    return 0;
}