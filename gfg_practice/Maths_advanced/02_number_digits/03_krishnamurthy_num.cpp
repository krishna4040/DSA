# include "bits/stdc++.h"
using namespace std;

int factorial[10];
void precomuprte()
{
    factorial[0] = 1;
    for (int i = 1; i <= 10; i++)
        factorial[i] = i * factorial[i-1];
}
bool iskrishnamuthy(int n)
{
    int sum = 0;
    int temp = n;
    while (n)
    {
        int lsd = n % 10;
        sum += factorial[lsd];
        n /= 10;
    }
    return (sum == temp);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}