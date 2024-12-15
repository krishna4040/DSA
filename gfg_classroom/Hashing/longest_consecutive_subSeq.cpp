# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

int longestConsecutive(int* arr , int n)
{
    sort(arr,arr+n);
    int res = 0;
    int count = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i+1]-arr[i] == 1)
            count++;
        else
            count = 1;
        res = max(res,count);
    }
    return res;
}

int longestsub(int *arr, int n)
{
    unordered_set<int> s(arr,arr+n);
    int res = 1;
    for (auto &&x : s)
    {
        if (s.find(x-1) == s.end())
        {
            int curr = 1;
            while (s.find(x+curr) != s.end())
                curr++;
            res = max(res,curr);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
    cout << longestsub(arr,11);
    return 0;
}