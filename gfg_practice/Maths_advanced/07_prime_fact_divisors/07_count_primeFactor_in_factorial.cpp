# include "bits/stdc++.h"
using namespace std;

/*Given a number ‘n’ and a prime number ‘p’. We need to find out the power of ‘p’ in the prime factorization of n!*/
//*Approach: Powerofp(n!) = floor(n/p) + floor(n/p^2) + floor(n/p^3)........ 
int countp(int n , int p)
{
    int ans = 0;
    int temp = p;
    while (temp <= n)
    {
        ans += n/temp;
        temp *= p;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << countp(10,2);
    return 0;
}