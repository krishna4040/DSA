# include "bits/stdc++.h"
using namespace std;

/*Sphenic num: positive integer n which is product of exactly three distinct primes. 
EX: 30 = 2x3x5*/
bool issphenic(int n)
{
    // algo: sphenic number will have only 8 divisors
    // issphenic no duplicates in prime factorization
    vector<int> v;
    while (n % 2 == 0)
    {
        v.push_back(2);
        n /= 2;
    }
    while (n % 3 == 0)
    {
        v.push_back(3);
        n /= 2;
    }
    for (int i = 5; i*i <= n; i+=6)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n /= i;
        }
        while (n % (i+2) == 0)
        {
            v.push_back(i+2);
            n /= (i+2);
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}