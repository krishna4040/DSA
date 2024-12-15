# include <iostream>
using namespace std;

bool ispower2(int n)
{
    if (n == 0)
        return 0;
    int x = n & (n-1);
    if (x == 0)
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
