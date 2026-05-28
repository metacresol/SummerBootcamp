// queue using array.

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
    if (rear == MAX - 1)
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
        printf("queue is empty");
        exit(1);
    }
    num = qu[front];
    printf("%d is deleted from queue\n", num);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front += 1;
    }
}
void enqueue()
{
    int num;
    if (isFull())
    {
        printf("queue is full! Overflow ");
        exit(1);
    }
    printf("enter number\n");
    scanf("%d", &num);
    if (front == -1)
    {
        front = 0;
    }
    rear = rear + 1;
    qu[rear] = num;
}
void display()
{
    if (isEmpty())
    {
        printf("queue is empty");
        exit(1);
    }
    int i = front;
    while (i <= rear)
    {
        printf("%d", qu[front]);
        i++;
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
            printf("Inserted elemnt is :");
            display();
            break;
        case 2:
            dqueue();
            break;
        case 3:
            printf("Queue:");
            display();
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}