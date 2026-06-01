#include <stdio.h>

int trap(int height[], int n)
{
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];

            left++;
        }
        else
        {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];

            right--;
        }
    }

    return water;
}

int main()
{
    int n;
    printf("enter the size of array :");
    scanf("%d", &n);

    int height[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &height[i]);

    printf("Trapped Water = %d\n", trap(height, n));

    return 0;
}