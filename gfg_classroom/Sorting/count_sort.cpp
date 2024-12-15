# include "bits/stdc++.h"
using namespace std;

void countSort(int arr[] , int n)
{
    int k = *max_element(arr,arr+n);
    int count[k] = {};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= k; i++)
        count[i] += count[i-1];
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    countSort(arr,5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
