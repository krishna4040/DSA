# include <iostream>
using namespace std;

int gcd(int a , int b)
{
    if (b == 0)
        return a;
    return gcd(b , a % b);
}

int lcm(int a , int b)
{
    return (a * b) / gcd(a , b);
}

int main(int argc, char const *argv[])
{
    int a , b;
    cin >> a >> b;
    cout << gcd(a , b);
    cout << lcm(a , b);
    return 0;
}