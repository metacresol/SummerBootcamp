// arr=[6,8,0,1,3]
//  greater ele=[6-8,8-(-1),0-1,1-3,3-(-1)]
// approach scanf from right to left and push the element into stack and pop the elment which is smaaler the upcoming element.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans(arr.size(), 0);
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }
    for (int k : ans)
    {
        cout << k << " ";
    }
}