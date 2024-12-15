/*Given an array arr[] sorted in ascending order of size N and an integer K. Check if K is present in the array or not.*/
# include "bits/stdc++.h"
using namespace std;

int bsearch(int arr[] , int n , int k)
{
    int low = 0 , high = n-1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (arr[mid] == k)
            return 1;
        else if (arr[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
