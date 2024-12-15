# include <iostream>
using namespace std;

bool palindrome(int n)
{
    int rev = 0;
    int org = n;
    while (n)
    {
        int lsd = n % 10;
        rev = rev * 10 + lsd;
        n /= 10;
    }
    if (org == rev)
        return 1;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << palindrome(n);
    return 0;
}