# include "bits/stdc++.h"
using namespace std;

// Do not return the index
int bsearch(int arr[] , int n , int x)
{
    bool found = binary_search(arr,arr+n,x);
    return found;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7};
    bsearch(arr,7,5);
    return 0;
}