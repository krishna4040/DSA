# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

vector<int> unionArr(int *A , int n , int *B , int m)
{
    vector<int> res;
    for (int i = 0; i < n; i++)
        res.push_back(A[i]);

    for (int i = 0; i < m; i++)
        res.push_back(B[i]);

    unordered_set<int> s;
    for (int i = 0; i < res.size(); i++)
        s.insert(res[i]);

    res.clear();
    for (auto &&i : s)
        res.push_back(i);
    return res;
}

int main(int argc, char const *argv[])
{
    int A[] = {1,2,3,4,5,6};
    int B[] = {4,5,6,7,8,9};
    vector<int> v = unionArr(A,6,B,6);
    for (auto &&i : v)
        cout << i << " ";

    return 0;
}