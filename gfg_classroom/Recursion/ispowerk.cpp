# include <iostream>
using namespace std;

int k = 2;
bool ispowerk(int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (n % k != 0)
        return 0;
    ispowerk(n/k);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << ispowerk(n);
    return 0;
}
