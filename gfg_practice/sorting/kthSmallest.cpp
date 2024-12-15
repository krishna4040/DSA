# include "bits/stdc++.h"
using namespace std;

int lomuto(int arr[] , int l , int h)
{
    int pivot = arr[h];
    int i = l-1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    return i+1;
}

int kthSmall(int arr[] , int n , int k)
{
    int l = 0 , h = n-1;
    while (l <= h)
    {
        int p = lomuto(arr,l,h);
        if (p == k-1)
            return arr[p];
        else if (p > k-1)
            h = p-1;
        else
            l = p+1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,5,30,12};
    cout << kthSmall(arr,4,2);
    return 0;
}