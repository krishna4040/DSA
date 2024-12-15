# include <iostream>
using namespace std;

// Derangement:
// can be explained as the permutation of the elements of a certain set in a way that no element of that set appears in their original positions.
// D(n, k) = nCk * D(n-k, 0))

int f(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * f(n-1);
}
int c(int n , int r){return f(n)/(f(r)*f(n-r));}
int D(int n , int k){return c(n , k) * D(n-k , 0);}

int main(int argc, char const *argv[])
{
    
    return 0;
}