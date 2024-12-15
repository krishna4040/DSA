# include "bits/stdc++.h"
using namespace std; 

bool ispalindrome(int n)
{
    int rev = 0;
    int temp = n;
    while (n)
    {
        int lsd = n % 10;
        rev = rev * 10 + lsd;
        n /= 10;
    }
    return (rev == temp);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}