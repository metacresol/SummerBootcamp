#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<char> s;
    // string rev = "";
    string exp;
    getline(cin, exp);
    for (char ch : exp) // hello world
    {
        if (ch != ' ')
            s.push(ch);
        else
        {
            while (!s.empty())
            {

                cout << s.top();
                s.pop();
            }
            cout << " ";
        }
    }
    while (!s.empty())
    {

        cout << s.top();
        s.pop();
    }

    return 0;
}