#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leaders(vector<int> &arr)
{
    int n = arr.size();

    vector<int> ans;

    int maxi = arr[n - 1];
    ans.push_back(maxi);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = leaders(arr);

    cout << "Leaders in the array are: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
