#include<iostream>
#include<queue>
#define size 5
using namespace std;
queue<int>q;
 void Enqueue(int x){
        q.push(x);
    }
int main(){
    int val;
    for(int i=0;i<size;i++){
        cin>>val;
        Enqueue(val);
    }
    return 0;
}