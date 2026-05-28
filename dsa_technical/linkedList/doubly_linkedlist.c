#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
int count = 0;
typedef struct node Node;
Node *head = NULL;
Node *tail = NULL;
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
        newnode->next = NULL;
        newnode->prev = NULL;
        head = tail = newnode;
    }
    // when we don't use the tail
    //  Node *temp = head;
    //  while (temp->next != NULL)
    //  {
    //      temp = temp->next;
    //  }
    //  temp->next = newnode;
    //  newnode->prev = temp;
    //  newnode->next = NULL;
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = NULL;
    tail = newnode;
}
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        printf("|%d|->", temp->data);
        temp = temp->next;
    }
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
        newnode->next = NULL;
        newnode->prev = NULL;
        head = tail = newnode;
    }
    newnode->prev = NULL;
    newnode->next = head;
    head = newnode;
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
        newnode->next = NULL;
        newnode->prev = NULL;
        head = tail = newnode;
    }
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = NULL;
    tail = newnode;
}
void insertAt_pos()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    Node *vtemp = temp->next;
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
    int len = count;
    if (pos >= 1 && pos <= len)
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            vtemp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        vtemp->prev = newnode;
    }
    else
    {
        printf("Invalid position\n");
    }
}
void delete_last()
{
    Node *ptr = head;
    if (head == NULL)
    {
        printf("doubly linkedlist is empty\n");
        exit(1);
    }
    if ((head->next == NULL) || (head == tail))
    {
        free(ptr);
        head = tail = NULL;
        return;
    }
    ptr = tail;
    (tail->prev)->next = NULL;
    tail = ptr->prev;
    free(ptr);
}
void delete_first()
{
    Node *ptr = head;
    if (head == NULL)
    {
        printf("doubly linkedlist is empty\n");
        exit(1);
    }
    if ((head->next == NULL) || (head == tail))
    {
        free(ptr);
        head = tail = NULL;
        return;
    }
    head = ptr->next;
    head->prev = NULL;
    free(ptr);
}
void deleteAt_given_position()
{
    if (head == NULL)
    {
        printf(" doubly linked list is empty\n");
        exit(1);
    }
    Node *ptr = head;
    Node *temp = ptr->next;
    if (ptr->next == NULL)
    {
        free(ptr);
        head = tail = NULL;
    }

    int pos;
    printf("enter position\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        head = ptr->next;
        head->prev = NULL;
        free(ptr);
    }
    int len = count;
    if (pos >= 1 && pos <= len)
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            ptr = ptr->next;
        }
        if (temp->next != NULL)
        {
            ptr->next = temp->next;
            (temp->next)->prev = ptr;
            free(temp);
        }
        else
        {
            ptr->next = NULL;
            free(temp);
        }
    }
}

int main()
{
    int choice = 0;
    int n;
    printf("-------------menu for doubly linked list--------------\n");
    while (choice != 9)
    {
        printf("1.create\n");
        printf("2.insertAt_first\n");
        printf("3.insertAt_last\n");
        printf("4.insertAt_pos\n");
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
            printf("program finished\n");
        }
    }

    return 0;
}