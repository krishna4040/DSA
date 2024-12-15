# include <iostream>
using namespace std;

bool check(int n , int k)
{
    int x = (1 << (k-1));
    if (n & x)
        return 1;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    int n , k;
    cin >> n >> k;
    cout << check(n , k);

    return 0;
}
