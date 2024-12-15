/*You are given a number n. You need to find the sum of digits of n.*/
# include <iostream>
using namespace std;

int digitsum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n%10 + digitsum(n/10));
}

int main(int argc, char const *argv[])
{
    cout << digitsum(153);
    return 0;
}
