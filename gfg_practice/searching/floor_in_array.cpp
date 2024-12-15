/*Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest
element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing).*/
# include "bits/stdc++.h"
using namespace std;
//* Approach: STL lower_bound and iterators
int findFloor(int arr[] , int n , int x)
{
    int l = 0 , h = n-1;
    while (l <= h)
    {
        int m = (l+h)/2;
        if (arr[m] <= x)
        {
            if (arr[m] == x)
                return m;
            else if (arr[m+1] < x)
                l = m+1;
            else
                return m;
        }
        else
            h = m-1;
    }
    return -1;
}


int main(int argc, char const *argv[])
{

    return 0;
}