# include "bits/stdc++.h"
using namespace std;

int search(int arr[] , int n , int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (arr[i] < x)
        i *= i;
    if (arr[i] == x)
        return i;
    int low = i/2+1 , high = i-1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (x < arr[mid])
            high = mid-1;
        else if (x > arr[mid])
            low = mid+1;
        else
            return mid;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,10,15,20,80,90,100,120,500};
    cout << search(arr,9,80);
    return 0;
}