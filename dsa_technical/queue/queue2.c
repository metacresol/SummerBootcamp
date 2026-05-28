//implementation of queue using linked list

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *front = NULL;
Node *rear = NULL;
int isempty()
{
    if (front == NULL)
        return 1;
    return 0;
}
void enqueue()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("can not enqueue elment in queue ! queue is full\n ");
        return;
    }
    int val;
    printf("enter the value\n");
    scanf("%d", &val);
    newnode->next = NULL;
    newnode->data = val;
    if (front == NULL)
    {
        front = rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}
void display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        printf("|%d|\t", temp->data);
        temp = temp->next;
    }
}
void dequeue()
{
    if ((isempty()))
    {
        printf("queue is empty\n");
        return;
    }
    Node *temp = front;
    printf("%d is dequeue from queue\n", temp->data);
    front = temp->next;
    free(temp);
}
void main()
{
    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    dequeue();
    display();
}