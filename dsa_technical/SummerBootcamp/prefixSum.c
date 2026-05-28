#include <stdio.h>
int main()
{
    int n;
    printf("enter the size of array\n");
    scanf("%d", &n);
    int arr[50];
    int prefix[50];
    printf("enter the values of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    prefix[0] = arr[0]; // because indexing starts from 0
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int r, l;
    printf("enter the range\n");
    scanf("%d%d", &l, &r);
    int sum = prefix[r] - prefix[l - 1];
    printf("%d", sum);
    return 0;
}