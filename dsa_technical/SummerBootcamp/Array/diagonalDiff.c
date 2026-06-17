//diagonal difference of matrices.
#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n][n];
    int psum = 0;
    int dsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == j) || (i + j) == n - 1)
            {
                psum += arr[i][j];
                dsum += arr[i][j];
            }
        }
    }
    if (psum > dsum)
        printf("%d", psum - dsum);
    else
        printf("%d", dsum - psum);

    return 0;
}