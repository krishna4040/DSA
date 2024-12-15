# include "bits/stdc++.h"
# include <random>
using namespace std;

int hoare(int arr[] , int l , int h , int p)
{
    swap(arr[l] , arr[p]);
    int pivot = arr[l];
    int i = l-1 , j = h+1;
    while (true)
    {
        do{
            i++;
        } while (arr[i] < pivot);
        do{
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i],arr[j]);
    }
}

void qs(int arr[] , int l , int h)
{
    begin:
        if (l < h)
        {
            int r = rand() % (h - l + 1) + l;
            int p = hoare(arr,l,h,r);
            qs(arr,l,p);
            l = p+1;
            goto begin;
        }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,5,4};
    qs(arr,0,5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}