# include "bits/stdc++.h"
using namespace std;

// Input: 65785412  Find Digital root: (6 + 5 + 7 + 8 + 5 + 4 + 1 + 2) = 38 => 11 => (1 + 1) = 2 
// The idea is based on the fact that for a non-zero number num, the digital root is 9 if the number is divisible by 9, else the digital root is (sum of digits of num) % 9.

int digitalRoot(int n)
{
    if (n % 9 == 0)
        return 9;
    int sum = 0;
    while (n)
    {
        int lsd = n % 10;
        sum += lsd;
        n /= 10;
    }
    return sum % 9;
}

int main(int argc, char const *argv[])
{
    cout << digitalRoot(65785412);
    return 0;
}