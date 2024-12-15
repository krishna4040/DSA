# include "bits/stdc++.h"
using namespace std;

void computeLPS(string str , int *lps)
{
    int n = str.length();
    int i = 1 , len = 0;
    lps[0] = 0;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            str[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                len = lps[len-1];
        }
    }
}

void printSearch(string pat , string txt)
{
    int n = txt.length();
    int m = pat.length();

    int *lps = new int[m];
    computeLPS(pat,lps);

    int i = 0 , j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j]){
            i++;
            j++;
        }
        if (j < m){
            cout << i-j << " ";
            j = lps[j-1];
        }
        else{
            if (j == 0)
                i++;
            else
                j = lps[j-1];
        }
    }
}

int main(int argc, char const *argv[])
{
    string s = "abcabcabcabcabcbabccabbacsabaabc";
    string p = "abc";
    printSearch(p,s);
    return 0;
}