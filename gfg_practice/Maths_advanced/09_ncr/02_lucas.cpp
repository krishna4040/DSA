# include <iostream>
using namespace std;

// C(n,r)=C(n,r-1)* (n-r+1)/r
//  C(n, r)%p = [ C(n-1, r-1)%p + C(n-1, r)%p ] % p

int c(int n , int r , int p)
{
    if (r == 0 || r == n)
        return 1;
    return ((c(n-1,r-1,p)%p + c(n-1,r,p)%p) % p);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}