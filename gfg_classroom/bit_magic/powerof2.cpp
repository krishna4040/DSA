# include <iostream>
using namespace std;

// Naive solution
bool ispower2(int n)
{
    while (n != 1)
    {
        if (n % 2 != 0)
            return 0;
        n /= 2;
    }
    return 1;
}

bool ispower2(int n)
{
    // any num that is power of 2 have only 1 set bit
    // using brian lehrigham algorithm
    if (n & (n-1) == 0)
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
