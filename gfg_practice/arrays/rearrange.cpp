/*Given an array arr[] of size N where every element is in the range from 0 to n-1. 
Rearrange the given array so that arr[i] becomes arr[arr[i]].*/

# include <iostream>
using namespace std;

void arrange(int arr[] , int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = temp[temp[i]];
}

int main(int argc, char const *argv[])
{
    int arr[] = {4,0,2,1,3};
    arrange(arr,5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    
    return 0;
}