#include "bits/stdc++.h"
using namespace std;

// Function to find the smallest window in the string s consisting
// of all the characters of string p.
vector<int> Rabinkarp(string txt, string pat)
{
    vector<int> res;
    int d = 5 , q = 7;
    int n = txt.length(), m = pat.length();

    int h = 1;
    for (int i = 1; i <= m - 1; i++)
        h = (h * d) % q;

    int p = 0, t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool flag = 1;
            for (int j = 0; j < m; j++)
                if (pat[j] != txt[i + m])
                {
                    flag = 0;
                    break;
                }
            if (flag)
                res.push_back(i);
        }
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
    return res;
}
void update(int *arr , int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}
int longestSubstring(string s , int x)
{
    int count[256] = {0};
    int res = 0 , curr = 0;
    for (int i = x; i < s.length(); i++)
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

string smallestWindow(string s, string p)
{
    vector<int> v = Rabinkarp(s,p);
    int len = 0 , idx = 0;
    for (auto &&i : v)
    {
        if (len > longestSubstring(s,i))
        {
            len = longestSubstring(s,i);
            idx = i;
        }
    }
    string res = "";
    for (int i = idx; i < len; i++)
        res += s[i];
    return res;
}

int main(int argc, char const *argv[])
{
    string S = "timetopractice";
    string P = "toc";
    cout << smallestWindow(S,P);
    return 0;
}