#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    string compressed = "";
    int count = 1;

    for (int i = 1; i <= s.length(); i++)
    {
        if (i < s.length() && s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            compressed += s[i - 1];
            compressed += to_string(count);
            count = 1;
        }
    }

    cout << "Compressed String: " << compressed;

    return 0;
}