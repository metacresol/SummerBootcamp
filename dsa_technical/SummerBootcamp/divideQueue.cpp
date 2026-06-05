#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    queue<int> q;
    queue<int> q1;
    queue<int> q2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    for (int i = 0; i < n / 2; i++)
    {
        q1.push(q.front());
        q.pop();
    }
    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}