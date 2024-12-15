/*Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.*/
# include "bits/stdc++.h"
using namespace std;

int countmerge(int arr[] , int l , int m , int h)
{
    int n1 = m-l+1 , n2 = h-m;
    int left[n1] , right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l+i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[m+1+i];

    int i = 0 , j = 0 , k = 0 ,res = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
            res+=n1-i;
        }
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    return res;
}

int inversion(int arr[] , int l , int h)
{
    int res = 0;
    if (l < h)
    {
        int m = (l+h)/2;
        res += inversion(arr,l,m);
        res += inversion(arr,m+1,h);
        res += countmerge(arr,l,m,h);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    cout << inversion(arr,0,4);
    return 0;
}