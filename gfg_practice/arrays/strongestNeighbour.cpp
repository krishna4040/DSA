/*Given an array arr[] of n positive integers. The task is to find the maximum for every adjacent pairs in the array.*/
# include <iostream>
using namespace std;

void strongestNeighbour(int arr[] , int n)
{
    for (int i = 0; i < n-1; i++)
    {
        cout << max(arr[i],arr[i+1]) << " ";
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    strongestNeighbour(arr,n);

    return 0;
}
