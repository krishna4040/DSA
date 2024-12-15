# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

bool check(vector<int> A, vector<int> B, int n)
{
    unordered_map<int,int> m1 , m2;

    for (int i = 0; i < n; i++)
        m1[A[i]]++;
    for (int i = 0; i < n; i++)
        m2[B[i]]++;
    for (auto &&i : m1)
    {
        auto itr = m2.find(i.first);
        if (itr == m2.end() || itr->second != i.second)
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}