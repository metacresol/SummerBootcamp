#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int hash[256] = {0};
    string result = "";

    for (char ch : str)
    {
        if (hash[ch] == 0)
        {
            hash[ch] = 1;
            result += ch;
        }
    }

    cout << "After removing duplicates: " << result;

    return 0;
}