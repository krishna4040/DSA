#include "bits/stdc++.h"
using namespace std;

#define q 7
#define d 5

void Rabinkarp(string txt, string pat)
{
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
                cout << i << " ";
        }
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main(int argc, char const *argv[])
{
    string s = "helloThisisKrishna";
    string p = "Krish";
    Rabinkarp(s, p);
    return 0;
}