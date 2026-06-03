// update value of doubluy linked list at given position.
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
class list
{
    Node *head = NULL;
    Node *tail = NULL;

public:
    void insert(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void Update(int idx, int val)
    {
        Node *temp = head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        temp->data = val;
    }
};

int main()
{
    list l;
    int n;
    cout << "enter the no of nodes";
    cin >> n;
    cout << "enter the value of nodes";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.insert(x);
    }
    int pos, value;
    cin >> pos >> value;
    l.Update(pos, value);
    l.display();
}
