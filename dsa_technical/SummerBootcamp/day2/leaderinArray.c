#include <stdio.h>

int main()
{
    int n;
    printf("enter the size of array");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Learder of array is :\n");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i + 1])
            continue;
        else
            printf("%d ", arr[i]);
    }
    printf("%d ", arr[n - 1]);

    return 0;
}