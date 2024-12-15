# include <iostream>
using namespace std;

/*WAP to print binary eqivalent of a decimal number*/
int d2b(int n)
{
    int ans = 0;
    while (n)
    {
        int bit = n & 1;
        ans = ans*10 + bit;
        n >>= 1;
    }
    return ans;
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
    complement(n);
    return 0;
}
