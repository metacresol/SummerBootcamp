#include<iostream>
#include<stack>
pending
using namespace std;
int main(){
    stack<char>st;
    string exp;
    getline(cin,exp);
    int n=exp.size();
    for(int i=0;i<n;i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            st.push(exp[i]);
        }
        else if(isalnum(exp[i])||exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
            continue;
        else{
            if(st.empty())
                return 0;
            else{
                if(( st.top()== '(' &&  exp[i]== ')') ||
                ( st.top()== '{' &&  exp[i]== '}') ||
                ( st.top()== '[' &&  exp[i]== ']')){
                st.pop();
                }
            }
        }
    }

}