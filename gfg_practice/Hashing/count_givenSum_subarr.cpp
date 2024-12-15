# include "bits/stdc++.h"
using namespace std;

int countsumSubarr(int *arr , int n , int sum)
{
    int count = 0;
    unordered_map<int,int> m;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == sum)
            count++;
        if (m.find(pre_sum-sum) != m.end())
            count += m[pre_sum-sum];
        m[pre_sum]++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}