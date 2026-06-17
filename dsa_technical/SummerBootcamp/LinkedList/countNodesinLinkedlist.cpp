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
            head = tail = newnode;
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
    void countNode()
    {
        Node *temp = head;
        int cnt = 0;
        while (temp->data != -1)
        {
            cnt++;
            temp = temp->next;
        }
        cout << "no of node in list is:" << cnt;
    }
};
int main()
{
    list l;
    int n;

    while (n != -1)
    {
        cin >> n;
        l.insert(n);
    }

    l.display();
    cout << endl;
    l.countNode();
    return 0;
}
