# include "bits/stdc++.h"
using namespace std;

// Recemas seq: a(0) = 0,
/*  if number is not already included in the sequence,
        a(n) = a(n - 1) - n 
    else 
        a(n) = a(n-1) + n.*/

vector<int> recemas(int n)
{
    vector<int> res;
    vector<int> :: iterator b = res.begin() , e = res.end();
    res.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (binary_search(b,e,i))
            res.push_back(res[i-1]-i);
        else
            res.push_back(res[i-1]+i);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> v = recemas(17);
    for (auto &&i : v)
        cout << i << " ";
    return 0;
}