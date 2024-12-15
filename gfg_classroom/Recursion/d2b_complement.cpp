# include <iostream>
using namespace std;

void d2b(int n)
{
    if (n == 0)
        return;

    d2b(n/2);
    cout << n % 2;
}

void complement(int n)
{
    if (n == 0 || n == 1)
    {
        cout << !n;
        return;
    }
    complement(n/2);
    cout << !(n%2);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    d2b(n);
    cout << endl;
    complement(n);
    return 0;
}
