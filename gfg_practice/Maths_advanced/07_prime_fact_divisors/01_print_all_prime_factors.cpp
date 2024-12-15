# include <iostream>
using namespace std;

// TC: root(n)
void printpf(int n)
{
    // A number can solely be represented in product of prime numbers
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n /=2;
    }
    while (n % 3 == 0)
    {
        cout << 3 << " ";
        n /= 3;
    }
    for (int i = 5; i*i <= n; i+=6)
    {
        while (n % i == 0)
            cout << i << " ";
        while (n % (i+2) == 0)
            cout << i+2 << " ";
    }
    if (n > 3)
        cout << n;
}

void printfactors(int n)
{
    int i;
    for (; i*i <= n; i++)
        if (n % i == 0)
            cout << i;
    for (; i >= 1; i--)
        if (n % i == 0)
            cout << n/i;
}

int main(int argc, char const *argv[])
{

    return 0;
}
