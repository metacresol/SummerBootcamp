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
void reverse()
{
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void main()
{
    create_node();
    create_node();
    create_node();
    printf("before reverse :");
    display();
    printf("\n");
    printf("after reverse :");
    reverse();
    display();
}