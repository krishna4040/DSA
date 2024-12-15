# include "bits/stdc++.h"
using namespace std;

// Mersene Prime: any prime no. of the form 2^k-1 ika amersene prime
bool ismersePrime(int n)
{
    int m = n+1;
    return ((m & (m-1)) == 0);
}

int main(int argc, char const *argv[])
{
    cout << ismersePrime(31);
    return 0;
}