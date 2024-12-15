# include <iostream>
using namespace std;

/*You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.*/
int change(int n , int m)
{
    int count = 0;
    while (n != m)
    {
        if ((n & 1) != (m & 1))
            count++;
        n >>= 1;
        m >>= 1;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n , m;
    cin >> n >> m;
    cout << change(n , m);
    return 0;
}
