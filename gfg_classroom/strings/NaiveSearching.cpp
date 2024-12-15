#include "bits/stdc++.h"
using namespace std;

void pattsearch(string txt, string pat)
{
    int n = txt.length(), m = pat.length();
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (pat[j] != txt[i + j])
                break;
        if (j == m)
            cout << i << " ";
    }
}

bool search(string pat, string txt, int q)
{
    for (int i = 0; i <= txt.length() - pat.length(); i++)
        if (txt.substr(i, pat.length()) == pat)
            return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    string s = "geeksgorgeeks";
    string pat = "eeks";
    return 0;
}