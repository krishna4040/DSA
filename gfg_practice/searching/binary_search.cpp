/*Given an array arr[] sorted in ascending order of size N and an integer K. Check if K is present in the array or not.*/
# include "bits/stdc++.h"
using namespace std;

int bsearch(int arr[] , int n , int k)
{
    bool found = binary_search(arr,arr+n,k);
    if (found)
        return 1;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
