/*You are given a number n. You need to find nth Fibonacci number.F(n)=F(n-1)+F(n-2); where F(1)=1 and F(2)=1*/
# include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}
