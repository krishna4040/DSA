# include "bits/stdc++.h"
using namespace std;

// Fibonacci series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144......
// Facts about fibonacci:
/*
    * f(n) = f(n-1) + f(n-2)
    * Fibonnaci series: Spiral of squares with side lengths which follow the Fibonacci sequence. 
    * lsd pattern: the last digit seq of fib num repeats in length of 60
    * Factors of Fibonacci number : On careful observation, we can observe the following thing :
        Every 3-rd Fibonacci number is a multiple of 2
        Every 4-th Fibonacci number is a multiple of 3
        Every 5-th Fibonacci number is a multiple of 5
        Every 6-th Fibonacci number is a multiple of 8
        The sum of any ten consecutive Fibonacci numbers is divisible by 11.
    * Cassini’s Identity: f(n-1)*f(n+1) – f(n)*f(n) = (-1)^n 
    * Bennets formula: Fn = {[(√5 + 1)/2] ^ n} / √5  (correct upto n < 71) (golden-ratio: p = (√5 + 1)/2)
    * Zeckendorf’s theorem: every positive integer can be written uniquely as a sum of distinct non-neighbouring Fibonacci numbers.
    * fibonnaci coding: use Zeckendorf’s theorem
    * Matrix exponentation O(log n)
*/
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n-1)+fib(n-2);
}
void printfib(int n)
{
    int t1 = 0;
    int t2 = 1;
    while (n)
    {
        int nextterm = t1 + t2;
        cout << t1;
        t1 = t2;
        t2 = nextterm;
        n--;
    }
}
int nthfib(int n)
{
    int p;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}