# include "bits/stdc++.h"
using namespace std;

int f(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * f(n-1);
}

long lRank(string s)
{
    int n = s.length() , res = 1 , count[256] = {0} , mul = f(n);

    for (int i = 0; i < n; i++)
        count[s[i]]++;

    for (int i = 1; i < 256; i++)
        count[i] += count[i-1];

    for (int i = 0; i < n-1; i++)
    {
        mul /= (n-i);
        res += count[s[i]-1]*mul;
        for (int j = s[i]; j < 256; j++)
            count[j]--;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "tucmhpqzwrgeixkjnaslvyfdbo";
    cout << lRank(s);

    return 0;
}