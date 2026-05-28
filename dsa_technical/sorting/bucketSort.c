#include<stdio.h>
#include<stdlib.h>
// incomplete 
struct node{
    float data;
    struct node * next;
};
void insertSorted(struct node**head,float num){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=num;
    ptr->next=NULL;
    struct node*temp;
    if((*head==NULL) || (*head->data>=ptr->data)){
        ptr->next=*head;
        *head=ptr;

    }
    else{
        temp=*head;
        while(temp->next!=NULL && temp->next->data=ptr->data){
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
    }
}
void bucketSort(float a[], int n){
    struct node*bucket [n];
    for(int i=0;i<n;i++){
        bucket[i]=NULL;
    }
    for(int i=0;i<n;i++){
        int bucketindex=(int)(a[i]*n);
        insertSorted(&bucket[bucketindex],a[i]);
    }
    int index=0;
    for(int i=0;i<n;i++){
        struct node*curr=bucket[i];
        while(curr){
            a[index]=curr->data;
            struct node *temp=curr;
            curr=curr->next;
            free(temp);
        }
    }
}