# include <iostream>
using namespace std;

/*Given a positive integer N. The task is to find factorial of N.*/
int fact(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}