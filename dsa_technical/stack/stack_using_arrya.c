#include <stdio.h>
#define MAX 5
int top = -1;
int arr[MAX];
int isfull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    return 0;
}
int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
void push(int val)
{
    if (isfull())
    {
        printf("Overflow!\n");
    }
    top += 1;
    arr[top] = val;
}
void display()
{
    int temp = top;
    while (temp != -1)
    {
        printf("|%d|", arr[temp]);
        temp -= 1;
    }
    printf("\n");
}
void pop()
{
    if (isempty())
    {
        printf("Underflow !\n");
    }
    printf("popped %d\n", arr[top]);
    top -= 1;
}
int main()
{
    int val;
    printf("enter the data\n");
    scanf("%d", &val);
    push(val);
    push(10);
    display();
    pop();
    display();
    return 0;
}