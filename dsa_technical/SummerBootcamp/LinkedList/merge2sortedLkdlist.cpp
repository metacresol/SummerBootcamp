#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
class list
{
    node *head = NULL;
    node *tail = NULL;

public:
    void insert(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
            head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void merge(list &l2)
    {
        node *temp1 = head;
        node *temp2 = l2.head;

        node *dummy = new node(-1);
        node *curr = dummy;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data <= temp2->data)
            {
                curr->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                curr->next = temp2;
                temp2 = temp2->next;
            }
            curr = curr->next;
        }

        if (temp1 != NULL)
            curr->next = temp1;

        if (temp2 != NULL)
            curr->next = temp2;

        head = dummy->next;

        delete dummy;
    }
};

int main()
{
    list l1, l2;
    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l1.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int y;
        cin >> y;
        l2.insert(y);
    }
    l1.merge(l2);
    l1.display();

    return 0;
}