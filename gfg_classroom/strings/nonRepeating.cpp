# include "bits/stdc++.h"
using namespace std;

char firstNonrepeating(string s)
{
    int count[256] = {0};
    for (int i = 0; i < s.length(); i++)
        count[s[i]]++;

    for (int i = 0; i < s.length(); i++)
        if (count[s[i]] == 1)
            return s[i];

    return '$';
}

int main(int argc, char const *argv[])
{
    return 0;
}