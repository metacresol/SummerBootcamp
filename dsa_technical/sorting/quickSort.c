#include <stdio.h>

// Function declaration
int partition(int arr[], int l, int h);

void quickSort(int arr[], int l, int h)
{
    int pivot;

    if (l < h)
    {
        pivot = partition(arr, l, h);

        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, h);
    }
}

int partition(int arr[], int l, int h)
{
    int i, j, temp, pivot;

    pivot = arr[l];
    i = l + 1;
    j = h;

    while (i <= j)
    {
        while (i <= h && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;
}

int main()
{
    int arr[] = {50, 30, 10, 40, 20, 80, 90, 70};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}