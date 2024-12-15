# include "bits/stdc++.h"
using namespace std;

// Newman-conway sequence: P(n) = P(P(n - 1)) + P(n - P(n - 1)) with seed values P(1) = 1 and P(2) = 1
// 1 1 2 2 3 4 4 4 5 6 7 7…
int newmanConway(int n)
{
    if (n == 1 || n ==2)
        return 1;
    return newmanConway(newmanConway(n-1))+newmanConway(n-newmanConway(n-1));
}

int main(int argc, char const *argv[])
{
    cout << newmanConway(10);
    return 0;
}