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
// 15->20->30
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

void create_node()
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
    tail->next = newnode;
    tail = newnode;
    tail->next = head;
}
void insertAt_first()
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

void insertAt_last()
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
        return;
    }
    tail->next = newnode;
    tail = newnode;
    tail->next = head;
}

void insertAt_pos()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
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
        return;
    }
    int pos;
    printf("enter the position for node\n");
    scanf("%d", &pos);
    if (pos >= 1 && pos <= count)
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("Invalid position\n");
    }
}
void delete_first()
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("circular linked list is empty\n");
        exit(1); // or return;
    }
    if (head == tail)
    {
        free(temp);
        head = tail = NULL;
    }
    head = head->next;
    tail->next = temp->next;
    free(temp);
}

void delete_last()
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("circular linked list is empty\n");
        exit(1); // or return;
    }
    if (head == tail)
    {
        free(temp);
        head = tail = NULL;
    }
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = head;
    free(tail);
    tail = temp;
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

int main()
{
    int choice = 0;
    int n;
    printf("-------------menu for  circular linked list-------------\n");
    while (choice != 9)
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
            insertAt_first();
            display();
            printf("\n");
            break;
        case 3:
            insertAt_last();
            display();
            printf("\n");
            break;
        case 4:
            insertAt_pos();
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