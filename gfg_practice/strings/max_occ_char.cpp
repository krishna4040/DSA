# include "bits/stdc++.h"
using namespace std;

// return max occ lexographicaly smaller char
char maxOcc(string s)
{
    unordered_map<char,int> m;
    for (int i = 0; i < s.length(); i++)
        m[s[i]]++;
    pair<char,int> res = {'z',-1};
    for (auto &&i : m)
    {
        if (i.second > res.second)
        {
            res.second = i.second;
            res.first = i.first;
        }
        if (i.second == res.second && i.first < res.first)
            res.first = i.first;
    }
    return res.first;
}

int main(int argc, char const *argv[])
{

    return 0;
}