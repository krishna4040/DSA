# include "bits/stdc++.h"
using namespace std;

void partition(int arr[] , int n , int x)
{
    int temp[n];
    int small_idx = 0;
    int greater_idx = n-1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= arr[x])
        {
            temp[small_idx] = arr[i];
            small_idx++;
        }
        else
        {
            temp[greater_idx] = arr[i];
            greater_idx--;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main(int argc, char const *argv[])
{
    int arr[] = {3,8,6,12,10,7};
    partition(arr,6,5);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";

    return 0;
}