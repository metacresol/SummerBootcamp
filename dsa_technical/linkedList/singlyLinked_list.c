#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *head = NULL;
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
int lengthOf_linkedlist()
{
    Node *temp;
    int count = 0;
    temp = head;
    if (head == NULL)
    {
        printf("linked list is empty\n");
        return 0;
    }
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
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
void insert_at_begining()
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
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        return; // very important ! need not to forget .
    }
    newnode->next = head;
    head = newnode;
}
void insert_at_last()
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
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        return; // very important ! need not to forget .
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertAt_postion()
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
    Node *temp = head;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        return; // very important ! need not to forget .
    }
    int pos;
    printf("enter the position :\n");
    scanf("%d", &pos);
    int len = lengthOf_linkedlist();
    if (pos >= 1 && pos <= len)
    {
        printf("valid postion");
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("invalid positon ! enter position again\n");
    }
}
void delete_first()
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    Node *ptr = head;
    if (ptr->next == NULL)
    {
        free(ptr);
        head = NULL;
    }

    head = ptr->next;
    free(ptr);
}
void delete_last()
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    Node *ptr = head;
    Node *temp;
    while (ptr->next != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = NULL;
    free(ptr);
}
void deleteAt_given_position()
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
        exit(1);
    }
    Node *ptr = head;
    if (ptr->next == NULL)
    {
        free(ptr);
        head = NULL;
        return;
    }

    int pos;
    printf("enter position\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        head = ptr->next;
        free(ptr);
        return;
    }
    Node *temp = ptr->next;
    int len = lengthOf_linkedlist();
    if (pos >= 1 && pos <= len)
    {
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
            temp = temp->next;
                }
        if (temp->next != NULL)
        {
            ptr->next = temp->next;
            free(temp);
        }
        else
        {
            free(temp);
            ptr->next = NULL;
        }
    }
}

int main()
{
    int choice = 0;
    int n;
    printf("-------------menu for linked list-------------\n");
    while (choice != 8)
    {
        printf("1.create\n");
        printf("2.insertAt_begining\n");
        printf("3.insertAt_last\n");
        printf("4.insertAt_position\n");
        printf("5.delete_first\n");
        printf("6.delete_last\n");
        printf("7.deleteAt_given_position\n");
        printf("8.exit\n");
        printf("enter your choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("enter the no: of nodes you want to create :\n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                create_node();
            }
            display();
            printf("\n");
            break;
        case 2:
            insert_at_begining();
            display();
            printf("\n");
            break;
        case 3:
            insert_at_last();
            display();
            printf("\n");
            break;
        case 4:
            insertAt_postion();
            display();
            printf("\n");
            break;
        case 5:
            delete_first();
            display();
            printf("\n");
            break;
        case 6:
            delete_last();
            display();
            printf("\n");
            break;
        case 7:
            deleteAt_given_position();
            display();
            printf("\n");
            break;
        case 8:
            exit(1);
        default:
            printf("");
        }
    }

    return 0;
}