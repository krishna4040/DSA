/*You are given an array arr(0-based index).
The size of the array is given by sizeOfArray. You need to insert an element at given index.*/
# include <iostream>
using namespace std;

void insert(int arr[] , int n , int pos , int x)
{
    int idx = pos - 1;
    for (int i = n-1; i >= idx; i--)
        arr[i+1] = arr[i];
    arr[idx] = x;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};
    insert(arr,6,2,4);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}