/*Given a string str and a pattern pat. You need to check whether the pattern is present or not in the given string. */
# include <iostream>
using namespace std;

bool searchPattern(string str, string pat)
{
    for (int i = 0; i < str.length(); i++)
    {
        string s = "";
        for (int j = i; j < str.length(); j++)
        {
            s += str[j];
            if (s == pat)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    cout << searchPattern("abcdef","bcd");
    return 0;
}