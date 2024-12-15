# include "bits/stdc++.h"
using namespace std;

//Given a binary string S. The task is to count the number of substrings that start and end with 1
int countSubstr(string s , int n)
{
    unordered_map<char,int> m;
    for (int i = 0; i < n; i++)
        m[s[i]]++;
    int count = m['1']*(m['1']-1)/2;
    return count;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}