# include "bits/stdc++.h"
using namespace std;

vector<int> Quadratic(int a , int b , int c)
{
    vector<int> sol;
    int d = (b*b) - (4*a*c);
    if (d >= 0)
    {
        int x = (-b + sqrt(d))/2*a;
        int y = (-b - sqrt(d))/2*a;
        sol.push_back(x);
        sol.push_back(y);
    }
    else
        sol.push_back(-1);
    return sol;
}

int main(int argc, char const *argv[])
{
    vector<int> v = Quadratic(1,5,6);
    for (auto &&i : v)
        cout << i << " ";
    return 0;
}