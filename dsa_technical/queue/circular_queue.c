// using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int qu[MAX];
int front = -1;
int rear = -1;
int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if (front == (rear + 1) % MAX)
    {
        return 1;
    }
    return 0;
}
void dqueue()
{
    int num;
    if (isEmpty())
    {
        printf("queue is empty!underflow\n");
        return;
    }
    num = qu[front];
    printf("%d is deleted from queue\n", num);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}
void enqueue()
{
    int num;
    if (isFull())
    {
        printf("queue is full ! Overflow\n");
        return;
    }
    printf("enter number: ");
    scanf("%d", &num);
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    qu[rear] = num;
}
void display()
{
    if (isEmpty())
    {
        printf("queue is empty");
        return;
    }
    int i = front;

    while (1)
    {
        printf("%d\t", qu[i]);
        if (i == rear)
        {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    int choice = 0;
    printf("-------------menu for queue-------------\n");
    while (choice != 4)
    {
        printf("1.enqueue()\n");
        printf("2.dqueue()\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter your choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            printf("Inserted element is :");
            display();
            break;
        case 2:
            dqueue();
            break;
        case 3:
            printf("Queue :");
            display();
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}