# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

bool issum(int *arr , int n , int sum)
{
    int pre_sum = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (s.find(pre_sum-sum) != s.end())
            return 1;
        if (pre_sum == sum)
            return 1;
        s.insert(pre_sum);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,8,6,13,3,-1};
    cout << issum(arr,6,22);
    return 0;
}