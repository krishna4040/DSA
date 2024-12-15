# include "bits/stdc++.h"
using namespace std;

int longestBinarr(int *arr , int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            arr[i] = -1;
    
    int pre_sum = 0 , res = 0;
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == 0)
            res = i+1;
        if (m.find(pre_sum) != m.end())
            res = max(res,i-m[pre_sum]);
        else
            m.insert({pre_sum,i});
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,0,1,1,1,0,0};
    cout << longestBinarr(arr,7);
    return 0;
}