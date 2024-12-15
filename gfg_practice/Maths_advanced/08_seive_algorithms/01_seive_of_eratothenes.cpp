# include "bits/stdc++.h"
using namespace std;

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

int main(int argc, char const *argv[])
{
    vector<int> v = seive(100);
    for (auto &&i : v)
        cout << i << " ";

    return 0;
}