#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *head = NULL;
Node *tail = NULL;
int count = 0;
void display()
{
    Node *temp = head;
    do
    {
        count++;
        printf("|%d|->", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void insert()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("memory is not allocated\n");
        exit(1);
    }
    int val;
    printf("enter the data of node\n");
    scanf("%d", &val);
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = head;
        head = tail = newnode;
    }
    newnode->next = head;
    head = newnode;
    tail->next = head;
}
void deleteAt_given_position()
{
    Node *temp = head;
    Node *ptr;
    if (head == NULL)
    {
        printf("circular linked list is empty\n");
        exit(1); // or return;
    }
    if (head == tail)
    {
        free(temp);
        head = tail = NULL;
        return;
    }
    int pos;
    printf("enter position\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        head = temp->next;
        tail->next = head;
        free(temp);
        return;
    }
    if (pos >= 1 && pos <= count)
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        ptr = temp->next;
        if (ptr->next == tail)
        {
            tail = temp;
            tail->next = head;
            free(ptr);
        }
        else
        {
            temp->next = ptr->next;
            free(ptr);
        }
    }
    else
    {
        printf("Invalid position\n");
    }
}
void main()
{
    for (int i = 0; i < 5; i++)
        insert();

    display();
    deleteAt_given_position();
    display();
}