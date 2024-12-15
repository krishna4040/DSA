# include "bits/stdc++.h"
using namespace std;

// Moser-De-Brojin seq: obtained by adding up the distinct powers of the number 4 (For example, 1, 4, 16, 64, etc).
int moserdeBrojin(int n)
{
    if (n ==0 || n == 1)
        return n;
    if (n % 2 == 0)
        return 4 * moserdeBrojin(n/2);
    else
        return 4 * moserdeBrojin(n/2) + 1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}