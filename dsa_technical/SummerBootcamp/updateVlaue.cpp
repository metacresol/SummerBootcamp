// update value of doubluy linked list at given position.
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val){
    data=val;
    prev=NULL;
    next=NULL; 
    }  
};
class list{
    Node*head=NULL;
    Node*tail=NULL;
    public:
        void insert(int val){
            Node * newnode=new Node(val);
            if(head==NULL){
                head=tail=NULL;
                return;
            }
            else{
                tail->next=newnode;
                newnode->prev=tail;
                tail=newnode;
            }
        }
        void display(){
            Node*temp=head;
            while(temp!=head){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }

};

int main(){
    list l;
    int n;
    cout<<"enter the no of nodes";
    cin>>n;
    cout<<"enter the value of nodes";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        l.insert(x);
    }
    l.display();
}
