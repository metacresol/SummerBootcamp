#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> Q;
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        Q.push(x);
    }
    cout << sum;
}