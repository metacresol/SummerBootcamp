#include <iostream>
#include <vector>
#define size 100
using namespace std;
class Stack
{
    int arr[size];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(int val)
    {
        if (top >= size - 1)
        {
            cout << "stack Overflow" << endl;
            return;
        }
        arr[++top] = val;
        cout << "Element is push into Stack." << endl;
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "stack is empty" << endl;
            return;
        }
        cout << "Element is poped out from stack" << arr[top--];
        cout << endl;
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        cout << "element at top is:";
        return arr[top];
    }
    bool isEmpty()
    {
        return top < 0;
    }
};
int main()
{
    Stack s;
    int n;
    cout << "enter the size of stack";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        s.push(val);
    }
    cout << "Top Element" << s.peek() << endl;
    s.pop();
    cout << "New Top Element: " << s.peek() << endl;

    return 0;
}

// class stack
// {
//     vector<int> st;

// public:
//     void push(int val)
//     {
//         st.push_back(val);
//         cout << "Element is push into Stack." << endl;
//     }
//     void pop()
//     {
//         if (st.empty())
//         {
//             cout << "stack is empty" << endl;
//             return;
//         }
//         cout << "Element is poped out from stack";
//         st.pop_back();
//         cout << endl;
//     }
//     int top()
//     {
//         if (st.empty())
//             return -1;
//         cout << "element at top is:";
//         return st.back();
//     }
//     bool isEmpty()
//     {
//         return st.empty();
//     }
//     int size()
//     {
//         return st.size();
//     }
// };
// int main()
// {
//     stack s;
//     int n;
//     cout << "enter the size of stack";
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int val;
//         cin >> val;
//         s.push(val);
//     }
//     cout << "Top Element" << s.top() << endl;
//     s.pop();
//     cout << "New Top Element: " << s.top() << endl;

//     return 0;
// }
