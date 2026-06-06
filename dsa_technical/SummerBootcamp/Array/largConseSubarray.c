#include <stdio.h>

// longest increasing contiguous subarray

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int curr = 1;
    int max = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            curr++;
        }
        else
        {
            curr = 1;
        }

        if (curr > max)
        {
            max = curr;
        }
    }

    printf("Maximum increasing subarray size is : %d", max);

    return 0;
}