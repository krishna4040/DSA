# include "bits/stdc++.h"
using namespace std;

// Krishnamurthy num: a number whose sum of the factorial of digits is equal to the number itself.
// EX: 1! + 4! + 5! = 1 + 24 + 120 = 145

int factorial[10];
void precompute_fact()
{
    factorial[0] = 0;
    for (int i = 1; i < 10; i++)
        factorial[i] = i * factorial[i-1];
}
bool iskrishnamurthy(int n)
{
    int sum = 0;
    int temp = n;
    while (n)
    {
        int lsd = n % 10;
        sum += factorial[lsd];
        n /= 10;
    }
    return (temp == sum);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}