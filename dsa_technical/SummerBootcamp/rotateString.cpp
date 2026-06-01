#include <iostream>
#include <string>
using namespace std;
int main()
{
    string old;
    getline(cin, old);

    string New(old.length(), ' ');

    int n;
    cin >> n;
    char ch;
    cin >> ch;
    if (ch == 'L' || ch == 'l')
    {
        for (int i = 0; i < old.length(); i++)
        {
            New[i] = old[(i + n) % old.length()];
        }
    }
    if (ch == 'r' || ch == 'R')
    {
        for (int i = 0; i < old.length(); i++)
        {
            New[i] = old[(i - n + old.length()) % old.length()];
        }
    }

    cout << New;
}