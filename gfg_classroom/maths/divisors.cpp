# include <iostream>
using namespace std;

void divisors(int n)
{
    int i;
    for (i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
        {
            cout << n / i << " ";
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    divisors(n);
    return 0;
}