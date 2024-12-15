# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

vector<int> countDistinct(int *arr , int n , int k)
{
    vector<int> res;
    for (int i = 0; i < n-k+1; i++)
    {
        unordered_set<int> s;
        for (int j = i; j < i+k; j++)
            s.insert(arr[j]);
        res.push_back(s.size());
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,20,10,30,40,10};
    vector<int> v = countDistinct(arr,7,4);
    for (auto &&i : v)
        cout << i << " ";

    return 0;
}