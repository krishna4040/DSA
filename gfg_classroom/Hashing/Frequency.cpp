# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

// We can calc frq of elements in arr in O(n) TC using STL unordered map

int nonRepeated(int *arr , int n)
{
    sort(arr,arr+n);
    int res = 0;
    for (int i = 1; i < n-1; i++)
        if (arr[i] != arr[i+1] && arr[i] != arr[i-1])
            res++;
    if (arr[n-1] != arr[n-2])
        res++;
    if (arr[0] != arr[1])
        res++;
    return res;
}

int NonRepeated(int *arr , int n)
{
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    int res = 0;
    for (auto &&i : m)
        if (i.second == 1)
            res++;
    return res;
}

int main(int argc, char const *argv[])
{

    return 0;
}