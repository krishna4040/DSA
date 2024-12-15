# include "bits/stdc++.h"
using namespace std;

// Jumbeled num: A number is said to be Jumbled if for every digit, its neighbours digit differs by max 1. EX: 6567
bool isJumbeled(int n)
{
    if (n / 10 == 0)
        return true;
    while (n)
    {
        if (n / 10 == 0)
            return true;
        int digit1 = n % 10;
        int digit2 = (n/10)%10;
        if (abs(digit1-digit2) != 1)
            return false;
        n /= 10;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cout << isJumbeled(6567);
    return 0;
}