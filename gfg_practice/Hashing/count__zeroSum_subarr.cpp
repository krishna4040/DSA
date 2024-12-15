# include "bits/stdc++.h"
using namespace std;

// count num of subarrays with zero sum
int countZeroSubarr(int *arr , int n)
{
    int count = 0;
    int pre_sum = 0;
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == 0)
            count++;
        if (m.find(pre_sum) != m.end())
            count += m[pre_sum];
        m[pre_sum]++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}