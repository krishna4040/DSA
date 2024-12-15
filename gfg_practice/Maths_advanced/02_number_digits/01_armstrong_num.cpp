# include "bits/stdc++.h"
using namespace std;

bool isarmstrong(int n)
{
    int sum = 0;
    int temp = n;
    while (n)
    {
        int lsd = n % 10;
        sum += lsd * lsd * lsd;
        n /= 10;
    }
    return (sum == temp);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}