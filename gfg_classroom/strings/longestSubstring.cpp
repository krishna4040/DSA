# include "bits/stdc++.h"
using namespace std;

void update(int *arr , int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}

int longestSubstring(string s)
{
    int count[256] = {0};
    int res = 0 , curr = 0;
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
        for (int j = 0; j < 256; j++)
        {
            if (count[j] > 1)
            {
                res = max(res,curr);
                curr = 0;
                update(count,256);
            }
        }
        curr++;
    }
    res = max(res,curr);
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "GeeksForGeeks";
    cout << longestSubstring(s);
    return 0;
}