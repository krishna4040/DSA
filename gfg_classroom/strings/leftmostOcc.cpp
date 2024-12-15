# include "bits/stdc++.h"
using namespace std;

int leftmost(string str)
{
    int count[256];
    fill(count,count+256,-1);
    int res = INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        int val = count[str[i]];
        if (val == -1)
            count[str[i]] = i;
        else
            res = min(res,val);
    }
    return (res == INT_MAX) ? -1 : res;
}

int leftmost(string s)
{
    bool visited[256] = {0};
    int res = -1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (visited[s[i]])
            res = i;
        else
            visited[s[i]] = 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}