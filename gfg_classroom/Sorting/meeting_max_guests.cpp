# include "bits/stdc++.h"
using namespace std;

int maxGuest(int arr[] , int dep[] , int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i = 1 , j = 0 , curr = 1 , res = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        res = max(res,curr);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}