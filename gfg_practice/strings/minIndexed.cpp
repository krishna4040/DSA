# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

//Given a string str and another string patt. Find the minimum index of the character in str that is also present in patt.
int minIndex(string str , string patt)
{
    unordered_set<char> s(patt.begin(),patt.end());
    for (int i = 0; i < str.length(); i++)
        if (s.find(str[i]) != s.end())
            return i;
    return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}