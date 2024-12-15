# include "bits/stdc++.h"
using namespace std;

// hoax num : similar to smith num but sum of digits only equals to sum of distinct prime factors
vector<int> seive(int n)
{
    vector<bool> v(n+1,true);
    for (int i = 2; i*i <= n; i++)
        if (v[i])
            for (int j = i*i; j <= n; j+=i)
                v[j] = false;
    vector<int> res;
    for (int i = 0; i < v.size(); i++)
        if (v[i])
            res.push_back(i);
    return res;
}

bool ishoax(int n)
{
    int count = 0;
    vector<int> v;
    for (int i = 2; i*i <= n; i++)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n /= i;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}