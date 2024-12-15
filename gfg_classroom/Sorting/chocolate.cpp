# include "bits/stdc++.h"
using namespace std;

int minChocodiff(int arr[] , int n , int m)
{
    sort(arr,arr+n);
    int res = INT_MAX;
    for (int i = 0; i < n-(n%m)-1; i++)
        res = min(res,arr[m-1+i]-arr[i]);
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3,4,1,9,56,7,9,12};
    cout << minChocodiff(arr,8,5);
    return 0;
}