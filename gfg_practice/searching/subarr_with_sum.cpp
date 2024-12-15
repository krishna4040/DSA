/*Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.
In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.
Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.*/
# include "bits/stdc++.h"
using namespace std;

vector<int> subarraySum(vector<int> arr , int n , long long s)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = arr[i];
        for (int j = i+1; j < n; j++)
        {
            if (curr_sum == s)
            {
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            curr_sum += arr[j];
        }
    }
    v.push_back(-1);
    return v;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v = subarraySum(arr,10,15);
    for (auto &&i : v)
        cout << i << " ";

    return 0;
}