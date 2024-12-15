# include <iostream>
using namespace std;

int ropecut(int n , int a , int b , int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max(ropecut(n-a,a,b,c) , ropecut(n-b,a,b,c) , ropecut(n-c,a,b,c));
    if (res == -1)
        return res;
    return res+1;
}

int main(int argc, char const *argv[])
{
    cout << ropecut(5,2,5,1);
    return 0;
}