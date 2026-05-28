#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;
typedef struct node Node;
Node *tail = NULL;
void display()
{
    Node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("linked list is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("|%d| ->", temp->data);
        temp = temp->next;
    }
}
void create_node()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    // checking whether memory is locatrd or not .
    if (newnode == NULL)
    {
        printf("memory is not allocated\n");
        exit(1);
    }
    int val;
    printf("enter the data of node\n");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = NULL;
    // checking whether node is present or not .
    if (head == NULL)
    {
        head = newnode;
        return; // very important ! need not to forget .
    }
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
}
void rotate(int k)
{
    Node *ptr = head;
    Node *temp;
    int ctr = 1;
    while (ctr < k && ptr->next != NULL)
    {
        ptr = ptr->next;
        ctr++;
    }
    if (ptr == NULL)
    {
        return;
    }
    temp = ptr;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head;
    head = temp->next;
    temp->next = NULL;
}
void main()
{
    int pos;
    printf("enter the position : ");
    scanf("%d", &pos);
    create_node();
    create_node();
    create_node();
    printf("linked list before rotation\n");
    display();
    printf("\n");
    rotate(pos);
    printf("linked list after rotation\n");
    display();
}