# include "bits/stdc++.h"
using namespace std;

// Factorial: n! = n*(n-1)!
/*
    * counting trailing zeroes: count number of 5s
    * counting digits in n!: use property of log
    * last non zero digit in fact
*/
int fact(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}