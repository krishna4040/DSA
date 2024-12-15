# include "bits/stdc++.h"
using namespace std;

int hoare(int arr[] , int l , int h)
{
    int pivot = arr[l];
    int i = l-1 , j = h+1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i],arr[j]);
    }
}

void quicksort(int arr[] , int l , int h)
{
    if (l < h)
    {
        int p = hoare(arr,l,h);
        quicksort(arr,l,p);
        quicksort(arr,p+1,h);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    quicksort(arr,0,4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    
    return 0;
}