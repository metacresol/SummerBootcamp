#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<char> s;
    string rev = "";
    string exp;
    getline(cin, exp);
    for (char ch : exp)
    {
        s.push(ch);
    }
    while (!s.empty())
    {
        rev += s.top();
        s.pop();
    }
    cout << rev;
}