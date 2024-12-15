# include "bits/stdc++.h"
using namespace std;

void countSort(int arr[] , int n , int e)
{
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i]/e)%10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];
    int op[n];
    for (int i = n - 1; i >= 0; i--)
        op[--count[(arr[i]/e)%10]] = arr[i];
    for (int i = 0; i < n; i++)
        arr[i] = op[i];
}
void radixSort(int arr[] , int n)
{
    int mx = *max_element(arr,arr+n);
    for (int exp = 0; mx/exp > 0; exp *= 10) 
        countSort(arr,n,exp);
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    radixSort(arr,5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}