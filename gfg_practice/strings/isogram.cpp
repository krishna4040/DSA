# include "bits/stdc++.h"
using namespace std;

bool issogram(string s)
{
    unordered_map<char,int> mp;
    for (int i = 0; i < s.length(); i++)
        mp[s[i]]++;
    for (auto &&i : mp)
        if (i.second > 1)
            return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}