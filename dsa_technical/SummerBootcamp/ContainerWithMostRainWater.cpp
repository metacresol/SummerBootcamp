#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of containers :";
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int ans = 0;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        int width = r - l;
        int height = min(vec[l], vec[r]);
        int curr = width * height;
        ans = max(curr, ans);
        if (vec[l] < vec[r])
            l++;
        else
            r--;
    }
    cout << "maximum water :" << ans;
    return 0;
}