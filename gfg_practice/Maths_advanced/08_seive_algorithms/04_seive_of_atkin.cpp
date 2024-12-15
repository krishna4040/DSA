#include <bits/stdc++.h>
using namespace std;

vector<bool> SieveOfAtkin(int n)
{
    vector<bool> sieve(n+1,false);

    if (n > 2)
        sieve[2] = true;
    if (n > 3)
        sieve[3] = true;

    /* Mark sieve[n] is true if one
    of the following is true:
        a)  n = (4*x*x)+(y*y) has odd number of
            solutions, i.e., there exist
            odd number of distinct pairs (x, y)
            that satisfy the equation and
            n % 12 = 1 or n % 12 = 5.
        b)  n = (3*x*x)+(y*y) has odd number of
            solutions and n % 12 = 7
        c)  n = (3*x*x)-(y*y) has odd number of
            solutions, x > y and n % 12 = 11 */
    for (int x = 1; x * x <= n; x++) 
    {
        for (int y = 1; y * y <= n; y++) 
        {
            // Condition 1
            int t = (4 * x * x) + (y * y);
            if (t % 12 == 1 || t % 12 == 5)
                sieve[t] = sieve[t] ^ true;

            // Condition 2
            t = (3 * x * x) + (y * y);
            if (t % 12 == 7)
                sieve[t] = sieve[t] ^ true;

            // Condition 3
            t = (3 * x * x) - (y * y);
            if (x > y && t % 12 == 11)
                sieve[t] = sieve[t] ^ true;
        }
    }

    // Mark all multiples
    // of squares as non-prime
    for (int r = 5; r * r <= n; r++) 
        if (sieve[r])
            for (int i = r * r; i <= n; i += r * r)
                sieve[i] = false;

    return sieve;
}

// Driver program
int main(void)
{
    vector<bool> v = SieveOfAtkin(20);
    for (int i = 2; i < 20; i++)
        if (v[i])
            cout << i << " ";
    return 0;
}