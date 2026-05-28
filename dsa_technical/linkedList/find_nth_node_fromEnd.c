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
void find_NthNOde(int k)
{
    Node *p1 = head;
    Node *p2 = head;
    for (int i = 0; i < k; i++)
    {
        if (p1 == NULL)
        {
            printf("list is shorter than %d", k);
            return;
        }
        p1 = p1->next;
    }
    while (p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    printf("%d is the node from end", p2->data);
}
void main()
{
    create_node();
    create_node();
    create_node();
    create_node();
    create_node();
    find_NthNOde(2);
}