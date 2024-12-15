# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

// remove common char and return a string with concatenated remaining char
string symmDiff(string s1 , string s2)
{
    unordered_set<char> s(s2.begin(),s2.end());
    unordered_set<char> t(s1.begin(),s1.end());
    string res = "";
    for (int i = 0; i < s1.length(); i++)
    {
        if (s.find(s1[i]) != s.end())
            continue;
        res += s1[i];
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (t.find(s2[i]) != t.end())
            continue;
        res += s2[i];
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s1 , s2;
    s1 = "aacdb";
    s2 = "gafd";
    cout << symmDiff(s1,s2);

    return 0;
}