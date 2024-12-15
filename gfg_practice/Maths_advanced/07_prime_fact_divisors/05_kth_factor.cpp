# include "bits/stdc++.h"
using namespace std;

// printing kth prime factor of n
int kthPrimeFactor(int n , int k)
{
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            count++;
            if (count == k)
                return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    cout << kthPrimeFactor(99,3);
    return 0;
}