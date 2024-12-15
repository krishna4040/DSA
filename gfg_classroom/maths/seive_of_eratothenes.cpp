# include "bits/stdc++.h"
using namespace std;

// TC: O(nloglogn)
void seive(int n)
{
    vector <bool> isprime(n+1 , true);
    for (int i = 2; i*i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i*i; j <= n; j+=i)
            {
                isprime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            cout << i << " ";
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    seive(n);
    return 0;
}