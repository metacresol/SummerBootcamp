#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    stack<int> st;
    for (int i = 0; i < 3; i++)
        st.push(i);
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (arr[a][b] == 1)
            st.push(b);
        else
            st.push(a);
    }
    int celeb = st.top();
    for (int i = 0; i < 3; i++)
    {
        if (i == celeb)
            continue;
        if (arr[i][celeb] == 0 || arr[celeb][i] == 1)
        {
            cout << "-1";
            return 0;
        }
    }
    cout << "celebrity is:" << celeb;
    return 0;
}