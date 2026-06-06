#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<char> s;
    int ch;
    char val;
    do
    {
        cout << "enter the choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "enter character" << endl;
            cin >> val;
            cout << "Adding Section:" << val << endl;
            s.push(val);
            break;
        }
        case 2:
        {
            if (s.empty())
                cout << "Stack is empty.Cannot pop." << "\n";
            else
            {
                cout << " Removing Section:" << s.top() << endl;
                s.pop();
            }
            break;
        }

        case 3:
        {
            stack<char> temp = s;

            while (!temp.empty())
            {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "Executing program." << endl;
            break;
        }
        default:
            cout << "Invalid case." << endl;
        }
    } while (ch != 4);
    return 0;
}