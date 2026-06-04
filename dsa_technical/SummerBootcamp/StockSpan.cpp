#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    stack<int> s;
    vector<int> price = {100, 80, 60, 70, 60, 75, 80, 85};
    vector<int> ans(price.size(), 0);
    for (int i = 0; i < price.size(); i++)
    {
        while (!s.empty() && price[s.top()] <= price[i])
        {
            s.pop();
        }
        if (s.empty())
            ans[i] = i + 1;
        else
            ans[i] = i - s.top();
        s.push(i);
    }
    for (int x : ans)
    {
        cout << x << " ";
    }
}