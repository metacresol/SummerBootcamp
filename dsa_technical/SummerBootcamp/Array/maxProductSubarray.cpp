#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        long long prod = 1;

        for (int j = i; j < n; j++)
        {
            prod *= nums[j];
            ans = max(ans, (int)prod);
        }
    }

    return ans;
}
int main()
{
    int n;
    cout << "enter the size of array: ";
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int res = maxProduct(nums);
    cout << "Max product sub array is:" << res;
    return 0;
}
