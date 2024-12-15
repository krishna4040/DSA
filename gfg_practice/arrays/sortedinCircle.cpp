/*Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing)
and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.*/
# include "bits/stdc++.h"
using namespace std;

void reverse(int arr[] , int l , int h)
{
    while (l <= h)
    {
        swap(arr[l],arr[h]);
        l++;
        h--;
    }
}
void rotate(int arr[] , int n , int d)
{
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}
bool issorted(int arr[] , int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i+1])
            return 0;
    }
    return 1;
}
bool issortedrotated(int arr[] , int n)
{
    int d = 1;
    for (int i = 0; i < n; i++)
    {
        rotate(arr,n,d);
        if (issorted(arr,n))
            return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3,4,1,2};
    cout << issortedrotated(arr,4);
    return 0;
}