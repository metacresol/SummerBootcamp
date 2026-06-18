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
    node *add(list &l2)
    {
        node *temp1 = head;
        node *temp2 = l2.head;
        node *dummy = new node(-1);
        node *curr = dummy;
        int carry = 0;
        while (temp1 != NULL || temp2 != NULL)
        {
            int sum = carry;
            if (temp1)
                sum += temp1->data;
            if (temp2)
                sum += temp2->data;
            node *newnode = new node(sum % 10);
            carry = sum / 10;
            curr->next = newnode;
            curr = curr->next;
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        if (carry)
        {
            node *newnode = new node(carry);
            curr->next = newnode;
        }
        return dummy->next;
    }
};
int main()
{
    list l1, l2;
    int n = 5, x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        l1.insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y;
        l2.insert(y);
    }
    cout << "list 1:";
    l1.display();
    cout << "\n list 2:";
    l2.display();
    node *ans = l1.add(l2);
    cout << "after adding linked list is : ";

    node *temp = ans;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}