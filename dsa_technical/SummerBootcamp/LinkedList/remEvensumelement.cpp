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
        int ori = x;
        int sum = 0;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        if (sum % 2 != 0)
        {
            ll.insert(ori);
        }
    }
    ll.display();
}