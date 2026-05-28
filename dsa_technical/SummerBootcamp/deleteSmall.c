#include <stdio.h>
#include <limits.h>
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
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    printf("array before removing smallest element is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("array after removing smallest element is :\n");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == min)
            continue;
        printf("%d ", arr[i]);
    }

    return 0;
}