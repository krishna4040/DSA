# include "bits/stdc++.h"
using namespace std;

// Sylvester’s sequence: is an integer sequence in which each member of the sequence is the product of the previous members, plus one.
# define N 1000000007
vector<long> sylvester(int n)
{
    vector<long> res;
    long temp = 1;
    long curr = 2;
    for (int i = 1; i <= n; i++)
    {
        res.push_back(curr);
        curr = (temp%N * curr%N) % N;  // curr *= temp
        temp = curr;
        curr = (curr+1) % N;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<long> v = sylvester(6);
    for (auto &&i : v)
        cout << i << " ";
    return 0;
}