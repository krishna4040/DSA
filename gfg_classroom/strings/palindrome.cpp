#include "bits/stdc++.h"
using namespace std;

bool ispalindrome(string str, int s, int e)
{
    if (s >= e)
        return 1;
    return (str[s] == str[e] && ispalindrome(str, s + 1, e - 1));
}

bool ispalindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return (rev == s);
}

bool ispal(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] != s[s.length() - i])
            return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    string s = "naman";
    cout << ispalindrome(s);
    return 0;
}