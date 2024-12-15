# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

/*Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character
of str1 to every character of str2 while preserving the order*/
bool isisomorphic(string s1 , string s2)
{
    if (s1.length() != s2.length())
        return 0;
    vector<pair<char,char>> v;
    for (int i = 0; i < s1.length(); i++)
        v.push_back(make_pair(s1[i],s2[i]));
    for (int i = 0; i < v.size(); i++)
        for (int j = i+1; j < v.size(); j++)
            if (v[i].first == v[j].first && v[i].second != v[j].second)
                return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    string s1 = "aba";
    string s2 = "xxy";
    isisomorphic(s1,s2);
    return 0;
}