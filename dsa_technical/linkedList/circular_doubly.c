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
        newnode->next = head;
        newnode->prev = tail;
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
    newnode->next = head;
    head->prev = newnode;
    tail = newnode;
}
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
        newnode->prev = tail;
        head = tail = newnode;
    }
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;
    tail->next = newnode;
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
        newnode->next = head;
        newnode->prev = tail;
        head = tail = newnode;
    }
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;
    tail = newnode;
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
        newnode->prev = tail;
        head = tail = newnode;
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
        }

        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        (temp->next)->prev = newnode;
    }
    else
    {
        printf("Invalid position\n");
    }
}
void delete_last()
{
    Node *ptr = tail;
    if (head == NULL)
    {
        printf("doubly linkedlist is empty\n");
        exit(1);
    }
    if (head == tail)
    {
        free(ptr);
        head = tail = NULL;
        return;
    }
    tail = ptr->prev;
    tail->next = head;
    head->prev = tail;
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
    head->prev = tail;
    tail->next = head;
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
    if (head == tail)
    {
        free(head);
        head = tail = NULL;
        return;
    }

    int pos;
    printf("enter position\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        head = head->next;
        free(ptr);
        head->prev = tail;
        tail->next = head;
        return;
    }
    int len = count;
    if (pos >= 1 && pos <= len)
    {
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        Node *temp = ptr->next;
        if (temp != tail)
        {
            ptr->next = temp->next;
            (temp->next)->prev = ptr;
            free(temp);
        }
        else
        {
            tail = ptr;
            tail->next = head;
            head->prev = tail;
            free(temp);
        }
    }
}

int main()
{
    int choice = 0;
    int n;
    printf("-------------menu for  circular doubly linked list--------------\n");
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