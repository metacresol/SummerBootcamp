#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *next;
} *head = NULL;
typedef struct node Node;
void create()
{
    int coeff;
    int expo;
    int n;
    printf("enter the no of terms\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the coeficient : ");
        scanf("%d", &coeff);
        printf("\n enter the value of exponent : ");
        scanf("%d", &expo);
        insert(coeff, expo);
    }
}
void insert(int co, int ex)
{
    Node *ptr, *temp;

    ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("memory is not allocated\n");
        exit(1);
    }
    ptr->next = NULL;
    ptr->coeff = co;
    ptr->expo = ex;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    else if (ex > head->expo)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->expo > ex)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return head;
}

void print()
{

    struct node *temp = head;
    if (head == NULL)
    {
        printf("expression is empty\n");
        return;
    }
    printf("Polynomial expression is :");
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL)
        {
            printf("+");
        }
        else
            printf("\n");
    }
}

void main()
{
    create();
    print();
}