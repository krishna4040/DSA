/*Given an array arr[] of size N of positive integers which may have duplicates.
The task is to find the maximum and second maximum from the array, and both of them should be different from each other,
so If no second max exists, then the second max will be -1.*/
# include "bits/stdc++.h"
using namespace std;

vector<int> maximums(int arr[] , int n)
{
    int res = -1 , largest = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        if (arr[i] != arr[largest])
            if (res == -1 || arr[i] > arr[res])
                res = i;
    }
    vector<int> ans;
    ans.push_back(arr[largest]);
    if(res==-1)
        ans.push_back(-1);
    else
        ans.push_back(arr[res]);
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
