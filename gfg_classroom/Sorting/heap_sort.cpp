# include "bits/stdc++.h"
using namespace std;

void maxheapify(int arr[] , int n , int i)
{
    int largest = i , left = 2*i+1 , right = 2*i+2;
    if (left < n && arr[left] > arr[largest]) {largest = left;}
    if (right < n && arr[right] > arr[largest]) {largest = right;}
    if (largest != i)
    {
        swap(arr[largest],arr[i]);
        maxheapify(arr,n,largest);
    }
}
void buildHeap(int arr[] , int n)
{
    for (int i = (n-2)/2; i >= 0; i--)
        maxheapify(arr,n,i);
}
void heapsort(int arr[] , int n)
{
    buildHeap(arr,n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0],arr[i]);
        maxheapify(arr,n,0);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    heapsort(arr,5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    
    return 0;
}
