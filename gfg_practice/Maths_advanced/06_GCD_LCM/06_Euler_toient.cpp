# include "bits/stdc++.h"
using namespace std;
// Euler’s Totient function Φ (n) for an input n is the count of numbers in {1, 2, 3, …, n-1} that are relatively prime to n i.e. GCD(n,i) = 1
// Relatively prime numbers: Coprime numbers(that do not divide each other)
/*
Propertie:
    * phi(p) = p-1
for two prime numbers:
    * phi(p.q) = phi(p).phi(q)
    * phi(p^k) = p^k - p^(k-1)
for two numbers
    * phi(a.b) = phi(a).phi(b).gcd(a,b)/phi(gcd(a,b))
    * summation(phi(factor of n)) = n
    * Euler's theorem: if n and a are coprime then ---> a^phi(n) ≡ 1
    * fermants little theorem ---> if n is prime n = p ---> a^(p-1) ≡ 1
*/

// Naive: O(N)
int phi(int n)
{
    int count = 1;
    for (int i = 2; i < n; i++)
        if (gcd(n,i) == 1)
            count++;
    return count;
}

// Formula: phi(n) = n x pi(1-1/p) , where p is peime factor of n : O(√n log n)
int phi(int n)
{
    // consider result as n
    // Consider all prime factors of n and subtract their multiples from result
    int result = n;
    for(int p = 2; p*p <= n; p++)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    // If n has a prime factor greater than sqrt(n)
    if (n > 1)
        result -= result / n;
    return result;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
