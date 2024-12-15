/*Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.*/
# include "bits/stdc++.h"
using namespace std;

int countnbyk(int arr[] , int n , int k)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i+1; j < n; j++)
            if (arr[i] == arr[j])
                count++;
        if (count > n/k)
            res++;
    }
    return res;
}

int countnbyk(int arr[] , int n , int k)
{
    int temp[n];
    copy_n(arr,arr+n,temp);
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {3,1,2,2,1,2,3,3};
    cout << countnbyk(arr,8,4);
    return 0;
}