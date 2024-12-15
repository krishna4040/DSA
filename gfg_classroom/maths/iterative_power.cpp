# include <iostream>
using namespace std;

int power(int x , int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res *= x;
        }
        x *= x;
        n /= 2;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}