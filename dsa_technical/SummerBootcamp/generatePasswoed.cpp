#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string name;
    string stu_id;
    getline(cin, name);
    getline(cin, stu_id);
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] >= 'A' && name[i] <= 'Z')
        {
            name[i] = name[i] + 32;
        }
    }
    stringstream ss(name);
    string word;
    string firstname = "";
    string lastname = "";
    bool firstwordfound = false;

    while (ss >> word)
    {
        if (!firstwordfound)
        {
            firstname = word;
            firstwordfound = "true";
        }
        lastname = word;
    }
    string username = firstname + "_" + lastname + stu_id;
    cout << username;
}