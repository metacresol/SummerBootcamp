// find left smaller ele and right smller ele and push the indexes into stack of element
// calcluate area using area=height * width . widht=r-l-1;
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    vector<int> arr = {2, 1, 5, 6, 1, 2, 3};
    vector<int> rs(arr.size(), 0);
    vector<int> ls(arr.size(), 0);
    stack<int> st;
    // right smallest element
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            rs[i] = arr.size();
        else
            rs[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            ls[i] = -1;
        else
            ls[i] = st.top();
        st.push(i);
    }
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int width = rs[i] - ls[i] - 1;
        int curr = arr[i] * width;
        res = max(curr, res);
    }
    cout << "largest reactangle in histogram is:" << res;
    return 0;
}
