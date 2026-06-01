// logic---> 1.sort 2.swap keeping first character same .

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());//because lexigraphical order .
    do
    {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));//swap internially keeping first character of string 
    return 0;
}