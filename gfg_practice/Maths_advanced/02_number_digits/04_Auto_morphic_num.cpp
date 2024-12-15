# include "bits/stdc++.h"
using namespace std;
// Automorphhic num: a num whose sq ends with the num itself
bool isAutomorphic(int n) {
    int square = n * n;
    while (n) 
    {
        if (n % 10 != square % 10)
            return false;
        n /= 10;
        square /= 10;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}