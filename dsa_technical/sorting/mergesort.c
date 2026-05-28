#include <stdio.h>
void mergeSort(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}
void merge(int a[], int l, int m, int h)
{
    int i = l, j = m + 1, k = l, b[20];
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i];
            i++;
        }
        else
        {
            b[k++] = a[j];
            j++;
        }
    }
    while (i <= m)
    {
        b[k++] = a[i++];
    }

    while (j <= h)
    {
        b[k++] = a[j++];
    }

    for (int i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}
void main()
{
    int arr[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
    int len = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}
