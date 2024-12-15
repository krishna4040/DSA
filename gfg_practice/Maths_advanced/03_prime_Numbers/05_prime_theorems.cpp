# include "bits/stdc++.h"
using namespace std;

// Hardy-Ramanujan: no. of distinct prime factors of a number n = log(log(n))
int HardyRamanujam(int n){return round(log(log(n)));}

// Rosser's Theorem: p(n) > n * (ln n)
int Rossers(int n){}

// Fermants littke theorem: Here p is a prime number  a^p ≡ a (mod p) 


int main(int argc, char const *argv[])
{
    cout << "No. of distinct prime divisors of n are " << HardyRamanujam(100);
    return 0;
}