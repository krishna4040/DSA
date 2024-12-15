# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

vector<int> intersection(int *A , int n , int *B , int m)
{
    vector<int> res;
    unordered_set<int> s(B,B+m);    // if order of op is acc to A

    for (int i = 0; i < n; i++)
        if (s.find(A[i]) != s.end())
            res.push_back(A[i]);
    return res;
}


int main(int argc, char const *argv[])
{
    int A[] = {10,20,30};
    int B[] = {30,20,10};
    vector<int> v = intersection(A,3,B,3);
    for (auto &&i : v)
        cout << i << " ";

    return 0;
}