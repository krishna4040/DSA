# include <iostream>
using namespace std;
/*If we subtract a smaller number from a larger one (we reduce a larger number), GCD doesn’t change. 
So if we keep subtracting repeatedly the larger of two, we end up with GCD.
Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find the remainder 0.*/
int gcd(int a , int b)
{
    if (b == 0)
        return a;
    return gcd(b,a%b);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}