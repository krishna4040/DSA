# include "bits/stdc++.h"
using namespace std;

// Primorial: pn# = multiplication of first n prime numbers
vector<int> seive(int n)
{
    vector<bool> isprime(n+1,true);
    for (int i = 2; i*i <= n; i++)
        if (isprime[i])
            for (int j = i*i; j <= n; j+=i)
                isprime[j] = false;
    vector<int> prime;
    for (int i = 2; i < isprime.size(); i++)
        if (isprime[i])
            prime.push_back(i);
    return prime;
}
int primorial(int k)
{
    vector<int> v = seive(1000);
    int m = 1;
    for (int i = 0; i < k; i++)
        m *= v[i];
    return m;
}

int main(int argc, char const *argv[])
{
    cout << primorial(3);
    return 0;
}