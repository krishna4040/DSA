# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

int LongestSubarr(int *arr , int n , int x)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int len = 1;
        int sum = arr[i];
        for (int j = i+1; j < n; j++)
        {
            if (sum == x)
                res = max(res,len);
            sum += arr[j];
            len++;
        }
    }
    return res;
}

int LongestSubarr(int *arr , int n , int x)
{
    unordered_map<int,int> m;
    int pre_sum = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == x)
            res = i + 1;
        if (m.find(pre_sum-x) != m.end())
            res = max(res , i-m[pre_sum-x]);
        if (m.find(pre_sum-x) == m.end())
            m.insert({pre_sum , i});
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,8,-4,-4,9,-2,-2};
    cout << LongestSubarr(arr,7,0);
    return 0;
}