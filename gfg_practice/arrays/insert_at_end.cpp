/*You are given an array arr. The size of the array is given by sizeOfArray. You need to insert an element at the end.
Array already have the sizeofarray -1 elements.*/
# include <iostream>
using namespace std;

void insert(int arr[] , int n , int x)
{
    arr[n-1] = x;
}

int main(int argc, char const *argv[])
{
    int arr[6] = {1,2,3};
    insert(arr,4,50);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}