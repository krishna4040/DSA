# include <iostream>
using namespace std;

/*Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers.*/
int diffbit(int n , int m)
{
    int count = 1;
    while (n || m)
    {
        if ((n & 1) == (m & 1))
            count++;
        else
            return count;
        n >>= 1;
        m >>= 1;
    }
}

int main(int argc, char const *argv[])
{
    int n , m;
    cin >> n >> m;
    cout << diffbit(n,m);
    return 0;
}
