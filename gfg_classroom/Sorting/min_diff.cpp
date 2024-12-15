# include "bits/stdc++.h"
using namespace std;

int mindiff(int arr[] , int n)
{
    sort(arr,arr+n);
    int mindiff = INT_MAX;
    for (int i = 0; i < n-1; i++)
        mindiff = min(mindiff , arr[i+1]-arr[i]);
    return mindiff;
}

int main(int argc, char const *argv[])
{
    int arr [] = {2, 4, 5, 9, 7};
    cout << mindiff(arr,5);
    return 0;
}