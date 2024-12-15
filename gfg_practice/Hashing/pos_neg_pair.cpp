# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

/*Given an array of distinct integers, find all the pairs having both negative and positive values of a number in the array.*/

vector<int> paair(int *arr , int n)
{
    vector<int> res;
    unordered_set<int> s(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        if (s.find(-arr[i]) != s.end() && arr[i] > 0)
        {
            res.push_back(-arr[i]);
            res.push_back( arr[i]);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,3,6,-2,-1,-3,2,7};
    vector<int> v = paair(arr,8);
    for (auto &&i : v)
        cout << i << " ";
    
    return 0;
}