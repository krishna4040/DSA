# include "bits/stdc++.h"
using namespace std;

// a(k+1) = [sqrt(a(k))   a(k) is even] && [sqrt[a(k)]^3  a(k) is odd]
// it can start with any positive number
// evntually last term is 1 it is a dec sequence
vector<int> printJuggler(int a)
{
    vector<int> juggler;
    juggler.push_back(a);
    while (a != 1)
    {
        int b = 0;
        if (a % 2 == 0)
            b = floor(sqrt(a));
        else
            b = floor(sqrt(a)*sqrt(a)*sqrt(a));
        juggler.push_back(b);
        a = b;
    }
    return juggler;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}