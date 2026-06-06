// update value of doubluy linked list at given position.

pending.
#include <iostream>
using namespace std;
class Node
{
public:
    string data;
    Node *next;
    Node(string val)
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
    void insert_front(string val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void match(string s){
        Node * temp=head;
        while(temp!=NULL){
            string str=temp->data;
            int p=0,q=0;
            bool ismatch=false;
            while(str[p]!='\0'&&s[q]!='\0'){
                if(str[p]!=s[q])
                    p++;
                else{
                    p++;q++;
                }
            }

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
    list l;
    int n;
    cout << "enter the no of nodes";
    cin >> n;
    cout << "enter the value of nodes";
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        l.insert_front(x);
    }
    string pattern;
    cin>>pattern;
    l.display();
}
