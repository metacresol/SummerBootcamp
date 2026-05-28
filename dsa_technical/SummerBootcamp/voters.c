#include <stdio.h>

int main()
{
    int n;
    printf("enter the size of the array\n");
    scanf("%d", &n);
    int arr[50];
    int hash[100] = {0}; // Initialize hash array to 0
    printf("enter the votes for each voter\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int key = n / 4;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < 100; i++)
    {
        if (hash[i] > key)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}