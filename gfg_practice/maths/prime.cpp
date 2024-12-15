# include <iostream>
using namespace std;

/*A prime number is a number which is only divisible by 1 and itself.
Given number N check if it is prime or not.*/
bool isprime(int n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i*i <= n; i+=6)
        if (n % i == 0 || n % (i+2) == 0)
            return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
