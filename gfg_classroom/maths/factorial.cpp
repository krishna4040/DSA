# include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}