# include "bits/stdc++.h"
using namespace std;

// Super-prime: those prime num that occupy prime positioons in seq of prime numbers are super prime
pair<vector<int>,vector<bool>> seive(int n)
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
    return make_pair(prime,isprime);
}
vector<int> superPrime(int n)
{
    pair<vector<int>,vector<bool>> v = seive(n);
    vector<int> res;
    for (int i = 2; i < v.first.size(); i++)
        if (v.second[i+1])
            res.push_back(v.first[i]);
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> v = superPrime(100);
    for (auto &&i : v)
        cout << i << " ";
    return 0;
}