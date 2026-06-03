// update value of doubluy linked list at given position.
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
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
    void rearrange()
    {
        Node *evenhead = NULL;
        Node *oddhead = NULL;
        Node *oddtail = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *newnode = new Node(temp->data);
            if (temp->data % 2 == 0)
            {
                newnode->next = evenhead;
                evenhead = newnode;
            }
            else
            {
                if (oddhead == NULL)
                {
                    oddhead = oddtail = newnode;
                }
                else
                {
                    oddtail->next = newnode;
                    oddtail = newnode;
                }
            }
            temp = temp->next;
        }
        if (evenhead == NULL)
        {
            head = oddhead;
            return;
        }
        Node *ptr = evenhead;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = oddhead;
        head = evenhead;
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
    l.rearrange();
    l.display();
}
