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
    int countOccur(int key)
    {
        int cnt = 0;
        node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data == key)
                cnt++;
            temp++;
        }
        return cnt;
    }
};
int main()
{
    list l;
    int n = 5;
    int key = 2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.insert(x);
    }
    l.display();
    int oucc = l.countOccur(key);
    cout << "no of occurance of key is :" << oucc;
    return 0;
}
