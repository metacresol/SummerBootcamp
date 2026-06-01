#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of array";
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int mid = 0;
    int low = 0;
    int high = n - 1;
    while (mid < high)
    {
        if (vec[mid] == 1)
            mid++;
        else if (vec[mid] == 0)
        {
            swap(vec[mid], vec[low]);
            low++;
            mid++;
        }
        else
        {
            swap(vec[mid], vec[high]);
            high--;
            mid++;
        }
    }
    for (int i : vec)
    {
        cout << i << " ";
    }
    return 0;
}
