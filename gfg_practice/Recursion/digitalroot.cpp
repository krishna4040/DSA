/*You are given a number n. You need to find the digital root of n.
DigitalRoot of a number is the recursive sum of its digits until we get a single digit number.*/
# include <iostream>
using namespace std;

int sumdigits(int n)
{
    int sum = 0;
    while (n)
    {
        int lsd = n % 10;
        sum += lsd;
        n /= 10;
    }
    return sum;
}

int digitalroot(int n)
{
    if (sumdigits(n) <= 9)
    {
        return sumdigits(n);
    }
    digitalroot(n/10);
}

int main(int argc, char const *argv[])
{
    cout << digitalroot(426693);
    return 0;
}