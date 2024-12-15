# include "bits/stdc++.h"
using namespace std;

int power(int x , int n)
{
    if (n == 0)
        return 1;
    int temp = power(x , n/2);
    temp *= temp;
    if (n % 2 == 0)
        return temp;
    else
        return temp * x;
}

int main(int argc, char const *argv[])
{
    int x , n;
    cin >> x >> n;
    cout << power(x , n);
    return 0;
}