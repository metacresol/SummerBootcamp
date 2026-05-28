#include <stdio.h>
void heapsort(int a[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

int main()
{
    int arr[] = {15, 5, 20, 1, 17, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr, n);
    printf("Sorted array after heap sort is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}