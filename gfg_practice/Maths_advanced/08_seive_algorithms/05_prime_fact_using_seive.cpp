# include "bits/stdc++.h"
using namespace std;

vector<int> sieve(int n)
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

vector<int> spf(int n)
{
    vector<int> prime = sieve(n);
    vector<int> prime_factor;
    for (int i = 2; i < prime.size(); i++)
        if (n % i == 0)
            prime_factor.push_back(i);
    return prime_factor;
}

int main(int argc, char const *argv[])
{
    int n = 15;
    vector<int> v = spf(n);
    for (auto &&i : v)
        cout << i <<" ";

    return 0;
}