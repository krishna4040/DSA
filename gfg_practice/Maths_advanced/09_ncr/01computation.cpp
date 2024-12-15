# include "bits/stdc++.h"
using namespace std;

/*C(n, r) = C(n-1, r-1) + C(n-1, r)     C(n, 0) = C(n, n) = 1*/
int c(int n , int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return c(n-1,r-1)+c(n-1,r);
}

// iterative approach
int f(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * f(n-1);
}
int c(int n , int r){return f(n)/(f(r)*f(n-r));}

// logrithimic method
// nCr = exp( log(n!) – log(r!) – log((n-r)!) )
int C(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    double res = 0;
    for (int i = 0; i < r; i++) 
        res += log(n-i) - log(i+1);
    return (int)round(exp(res));
}

int main(int argc, char const *argv[])
{
    
    return 0;
}