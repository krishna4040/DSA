# include <iostream>
using namespace std;

int countsetbits(int n , int r)
{
    if (n > 0)
        return ((n % r) + countsetbits(n/r , r));
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    cout << countsetbits(513,2);
    return 0;
}