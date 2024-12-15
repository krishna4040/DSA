# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

int longestCommon(int *arr1 , int *arr2 , int n)
{
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr1[i] - arr2[i];
    int pre_sum = 0;
    int res = 0;
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        pre_sum += temp[i];
        if (pre_sum == 0)
            res = i+1;
        if (m.find(pre_sum) != m.end())
            res = max(res , i-m[pre_sum]);
        m[pre_sum]++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}