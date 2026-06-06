#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;
typedef struct node Node;
Node *tail = NULL;
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
int detectLoop()
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
void main()
{
    create_node();
    create_node();
    create_node();
    if (detectLoop())
    {
        printf("loop is present");
    }
    else
    {
        printf("loop is not present");
    }
}