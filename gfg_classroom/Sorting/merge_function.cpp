# include "bits/stdc++.h"
using namespace std;

void merge(int arr[] , int l , int m , int h)
{
    int n1 = m-l+1 , n2 = h-m;
    int left[n1] , right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l+i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[m+1+i];

    int i = 0 , j = 0 , k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[i])
        {
            arr[k] = left[i];
            i++;k++;
        }
        else
        {
            arr[k] = right[j];
            j++;k++;
        }
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;k++;
    }
}

int main(int argc, char const *argv[])
{
    int arr[]= {1,3,5,7,2,4,6};
    merge(arr,0,3,7);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    return 0;
}