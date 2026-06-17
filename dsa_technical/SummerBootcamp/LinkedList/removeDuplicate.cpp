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
    void remove()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty\n";
            return;
        }

        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                if (temp->data == (temp->next)->data)
                {
                    Node *curr = temp->next;
                    temp->next = curr->next;
                    delete curr;
                }
                else
                    temp = temp->next;
            }
        }
    }
};
int main()
{
    list ll;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ll.insert(x);
    }
    cout << "linked list before deletion of dublicate value:\n";
    ll.display();
    cout << endl;
    cout << "linked list after deletion of dublicate value:\n";
    ll.remove();
    ll.display();
    return 0;
}