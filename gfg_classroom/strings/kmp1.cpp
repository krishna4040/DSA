# include "bits/stdc++.h"
using namespace std;

void lps(string str , int *lps)
{
    int n = str.length() , len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
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

int main(int argc, char const *argv[])
{
    string s = "ababacbaba";
    int n = s.length();
    int *arr = new int[n];
    lps(s,arr);
    for (int i = 0; i < n; i++)
        cout << arr[i];
    return 0;
}