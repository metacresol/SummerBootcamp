#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
    data=val;
    next=NULL; 
    }  
};
class list{
    Node*head=NULL;
    Node*tail=NULL;
    public:
        void insertFront(int val){
            Node * newnode=new Node(val);
            if(head==NULL){
                head=tail=newnode;
                return;
            }
            else{
                newnode->next=head;
                head=newnode;
            }
        }
        void display(){
            Node*temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        void segregate(){

        }

};
int main(){

}