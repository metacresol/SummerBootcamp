#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *top = NULL;
int isempty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

void push()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf(" Overflow ! stack is full\n");
        return;
    }

    int val;

    printf("enter the value you want to push\n");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}
void pop()
{
    if (isempty())
    {
        printf("Underflow! cann't delete from stack\n");
        return;
    }
    Node *temp;
    temp = top;

    // extra hai no need to do this
    // if (top->next == NULL)
    // {
    //     printf("Popped element: %d\n", top->data);
    //     free(temp);
    //     top= NULL;
    //     return;
    // }
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}
void display()
{
    Node *temp = top;
    if (isempty())
    {
        printf("stack is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

int main()
{
    printf("enter some values in stack\n");
    push();
    push();
    push();
    display();  
    pop();
    display();
    return 0;
}