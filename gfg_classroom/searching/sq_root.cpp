/*Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).*/
# include <iostream>
using namespace std;

long long sqroot(long long x)
{
    long long low = 1 , high = x , ans = -1;
    while (low <= high)
    {
        long long m = (low+high)/2;
        if (m*m == x)
            return m;
        else if (m*m > x)
            high = m - 1;
        else
        {
            low = m + 1;
            ans = m;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << sqroot(15);
    return 0;
}
