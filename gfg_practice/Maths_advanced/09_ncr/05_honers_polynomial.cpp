# include <iostream>
using namespace std;

// (a + b)^n = C(n,0) * a^n + C(n,1) * a^(n-1) * b + C(n,2) * a^(n-2) * b^2 + ... + C(n,n-1) * a * b^(n-1) + C(n,n) * b^n

// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
int horner(int poly[], int n, int x)
{
    int result = poly[0];
    for (int i=1; i<n; i++)
        result = result*x + poly[i];
    return result;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}