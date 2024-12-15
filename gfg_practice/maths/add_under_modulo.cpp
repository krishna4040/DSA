# include <iostream>
using namespace std;

/*Given two numbers a and b, find the sum of a and b. Since the sum can be very large, find the sum modulo 10^9+7.*/
long long modulo(long long a , long long b)
{
    long long m = 1E9 + 7;
    return ((a % m) + (b % m)) % m;
}

int main(int argc, char const *argv[])
{
    long long a , b;
    cin >> a >> b;
    cout << modulo(a , b);
    return 0;
}