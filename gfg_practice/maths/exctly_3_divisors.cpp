# include "bits/stdc++.h"
using namespace std;

bool isprime(int n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i*i <= n; i+=6)
    {
        if (n % i == 0 || n % (i+2) == 0)
            return 0;
    }
    return 1;
}

int count3divisors(int n)
{
    int p = 2;
    int ans = 0;
    while (p * p <= n)
    {
        if (isprime(p))
        {
            ans++;
        }
        p++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
