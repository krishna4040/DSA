# include <iostream>
using namespace std;

/*Given a number N and a bit number K, check if Kth bit of N is set or not. A bit is called set if it is 1.
Position of set bit '1' should be indexed starting with 0 from LSB side in binary representation of the number.*/
bool check(int n , int k)
{
    int x = (1 << k);
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
