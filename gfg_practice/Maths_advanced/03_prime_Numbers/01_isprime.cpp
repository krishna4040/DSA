# include "bits/stdc++.h"
using namespace std;

bool isprime(int n)
{
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i*i <= n; i+=6)
        if (n % i == 0 || n % (i+2) == 0)
            return 0;
    return 1;
}
// Other primirility chechk algorithms:
/*
    * Vantieghems Theorem: O(n)
    * AKS test: O(n^2)
    * Lucas test: O(nlogn)
    * miller rabin test: O(nlogn)
*/


int main(int argc, char const *argv[])
{
    
    return 0;
}