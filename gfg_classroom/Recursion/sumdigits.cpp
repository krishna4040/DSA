# include <iostream>
using namespace std;

int sumdigit(int n)
{
    if (n <= 9)
        return n;
    return n%10 + sumdigit(n/10);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << sumdigit(n);
    return 0;
}
