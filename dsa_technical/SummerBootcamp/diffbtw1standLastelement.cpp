#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of array" << endl;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "difference :" << arr[0] - arr[n - 1];
    return 0;
}
