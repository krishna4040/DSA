# include "bits/stdc++.h"
using namespace std;
class Natural
{
private:
    int a;
public:
    Natural(int a){this->a = a;}
    int naturalsum(int n){return n*(n+1)/2;}
    int sqnaturalsum(int n){return n*(n+1)*(2*n+1)/6;}
    int cubenaturalsum(int n){return n*n*(n+1)*(n+1)/4;}
    ~Natural(){}
};

// TC of pow: O(log n)
//* finding sum of series: 2,22,222,2222....... upto n terms
//  GP formula: 2(k)/81 x [10 x (10^n - 1) - 9xn]
int getsum2(int n){
    return 0.02469 * (10*(pow(10, n) - 1)- (9 * n));
}

//* finding sum of series: 0.6, 0.06, 0.006, 0.0006....to n terms
//  GP formula: 6/9 x [1 - 1/(10^n)]
int getsum06(int n){
    return (0.666) * (1 - 1 / pow(10, n));
}
int main(int argc, char const *argv[])
{
    cout << getsum2(3);
    Natural n(10);
    cout << n.naturalsum(10);
    return 0;
}