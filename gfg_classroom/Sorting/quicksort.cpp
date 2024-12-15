# include "bits/stdc++.h"
using namespace std;

int lomuto(int arr[] , int l , int h)
{
    int p = arr[h];
    int i = l-1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < p)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
int hoare(int arr[] , int l , int h)
{
    int pivot = arr[l];
    int i = l-1 , j = h+1;
    while (1)
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

void qsort_lomuto(int arr[] , int l , int h)
{
    if (l < h)
    {
        int p = lomuto(arr,l,h);
        qsort_lomuto(arr,l,p-1);
        qsort_lomuto(arr,p+1,h);
    }
}
void qsort_hoare(int arr[] , int l , int h)
{
    if (l < h)
    {
        int p = hoare(arr,l,h);
        qsort_hoare(arr,l,p);
        qsort_hoare(arr,p+1,h);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    return 0;
}